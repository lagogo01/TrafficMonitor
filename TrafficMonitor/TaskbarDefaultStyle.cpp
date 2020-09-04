#include "stdafx.h"
#include "TaskbarDefaultStyle.h"
#include "IniHelper.h"
#include "TrafficMonitor.h"

CTaskbarDefaultStyle::CTaskbarDefaultStyle()
{
}

CTaskbarDefaultStyle::~CTaskbarDefaultStyle()
{
	SaveConfig();
}

void CTaskbarDefaultStyle::LoadConfig()
{
	CIniHelper ini{ theApp.m_config_path };
	for (int i = 0; i < TASKBAR_DEFAULT_STYLE_NUM; i++)
	{
		wchar_t buff[64];
		swprintf_s(buff, L"default%d_", i + 1);
		wstring key_name = buff;
		ini.GetIntArray(L"taskbar_default_style", (key_name + L"text_color").c_str(), (int*)m_default_style[i].text_colors, TASKBAR_COLOR_NUM, RGB(255, 255, 255));
		m_default_style[i].back_color = ini.GetInt(L"taskbar_default_style", (key_name + L"back_color").c_str(), 0);
		m_default_style[i].transparent_color = ini.GetInt(L"taskbar_default_style", (key_name + L"transparent_color").c_str(), 0);
		m_default_style[i].status_bar_color = ini.GetInt(L"taskbar_default_style", (key_name + L"status_bar_color").c_str(), 0x005A5A5A);
		m_default_style[i].specify_each_item_color = ini.GetBool(L"taskbar_default_style", (key_name + L"specify_each_item_color").c_str(), false);
	}
}

void CTaskbarDefaultStyle::SaveConfig() const
{

	CIniHelper ini{ theApp.m_config_path };
	for (int i = 0; i < TASKBAR_DEFAULT_STYLE_NUM; i++)
	{
		wchar_t buff[64];
		swprintf_s(buff, L"default%d_", i + 1);
		wstring key_name = buff;
        if (IsTaskBarStyleDataValid(m_default_style[i]))           //����ǰ��鵱ǰ��ɫԤ���Ƿ���Ч
        {
            ini.WriteIntArray(L"taskbar_default_style", (key_name + L"text_color").c_str(), (int*)m_default_style[i].text_colors, TASKBAR_COLOR_NUM);
            ini.WriteInt(L"taskbar_default_style", (key_name + L"back_color").c_str(), m_default_style[i].back_color);
            ini.WriteInt(L"taskbar_default_style", (key_name + L"transparent_color").c_str(), m_default_style[i].transparent_color);
            ini.WriteInt(L"taskbar_default_style", (key_name + L"status_bar_color").c_str(), m_default_style[i].status_bar_color);
            ini.WriteBool(L"taskbar_default_style", (key_name + L"specify_each_item_color").c_str(), m_default_style[i].specify_each_item_color);
        }
        else
        {
            //д����־
            CString log_str;
            log_str.Format(_T("�ڱ���Ԥ��%dʱ��⵽����ɫ��������ɫ��Ϊ��ɫ����Ԥ��δ�����档"), i);
            CCommon::WriteLog(log_str, theApp.m_log_path.c_str());
            return;
        }
	}
	ini.Save();
}

void CTaskbarDefaultStyle::ApplyDefaultStyle(int index, TaskBarSettingData & data) const
{
    if (!IsTaskBarStyleDataValid(m_default_style[index]))
        return;

    if (index == TASKBAR_DEFAULT_LIGHT_STYLE_INDEX)
	{
		ApplyDefaultLightStyle(data);
	}
	else if(index >= 0 && index < TASKBAR_DEFAULT_STYLE_NUM)
	{
		for (int i{}; i < TASKBAR_COLOR_NUM; i++)
            data.text_colors[i] = m_default_style[index].text_colors[i];
		data.back_color = m_default_style[index].back_color;
		data.transparent_color = m_default_style[index].transparent_color;
		data.status_bar_color = m_default_style[index].status_bar_color;
		data.specify_each_item_color = m_default_style[index].specify_each_item_color;
		if (data.transparent_color == data.back_color)
		{
			CCommon::TransparentColorConvert(data.back_color);
			CCommon::TransparentColorConvert(data.transparent_color);
		}
	}
}

void CTaskbarDefaultStyle::ApplyDefaultLightStyle(TaskBarSettingData& data)
{
	for (int i{}; i < TASKBAR_COLOR_NUM; i++)
		data.text_colors[i] = RGB(0, 0, 0);
	data.back_color = RGB(210, 210, 211);
	data.transparent_color = RGB(210, 210, 211);
	data.status_bar_color = RGB(165, 165, 165);
}

void CTaskbarDefaultStyle::ModifyDefaultStyle(int index, TaskBarSettingData & data)
{
	if (index < 0 || index >= TASKBAR_DEFAULT_STYLE_NUM)
		return;

	for (int i{}; i < TASKBAR_COLOR_NUM; i++)
		m_default_style[index].text_colors[i] = data.text_colors[i];
	m_default_style[index].back_color = data.back_color;
	m_default_style[index].transparent_color = data.transparent_color;
	m_default_style[index].status_bar_color = data.status_bar_color;
	m_default_style[index].specify_each_item_color = data.specify_each_item_color;
}

bool CTaskbarDefaultStyle::IsTaskbarTransparent(const TaskBarSettingData& data)
{
	if (theApp.m_win_version.IsWindows10LightTheme() || theApp.m_win_version.IsWindows8Or8point1())
		return (data.transparent_color == data.back_color);
	else
		return data.transparent_color == 0;
}

void CTaskbarDefaultStyle::SetTaskabrTransparent(bool transparent, TaskBarSettingData& data)
{
	if (transparent)
	{
		if (theApp.m_win_version.IsWindows10LightTheme() || theApp.m_win_version.IsWindows8Or8point1())
		{
			//ǳɫģʽ��Ҫ��������������͸����ֻ�轫͸��ɫ���óɺͱ���ɫһ������
			CCommon::TransparentColorConvert(data.back_color);
			data.transparent_color = data.back_color;
		}
		else
		{
			//��ɫģʽ�£�����ɫ͸����͸��ɫ���óɺ�ɫ
			data.transparent_color = 0;
		}
	}
	else
	{
		//Ҫ�������������ڲ�͸����ֻ�轫͸��ɫ���óɺͱ���ɫ��һ������
		if (data.back_color != TASKBAR_TRANSPARENT_COLOR1)
			data.transparent_color = TASKBAR_TRANSPARENT_COLOR1;
		else
			data.transparent_color = TASKBAR_TRANSPARENT_COLOR2;
	}
}

bool CTaskbarDefaultStyle::IsTaskBarStyleDataValid(const TaskBarStyleData& data)
{
    for (int i{}; i < TASKBAR_COLOR_NUM; i++)
    {
        if (data.text_colors[i] != data.back_color)
            return true;
    }
    return false;     //����ı���ɫȫ�����ڱ�����ɫ�������ɫԤ����Ч
}
