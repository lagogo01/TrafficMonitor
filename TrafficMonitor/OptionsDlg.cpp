// OptionsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TrafficMonitor.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// COptionsDlg �Ի���

IMPLEMENT_DYNAMIC(COptionsDlg, CBaseDialog)

COptionsDlg::COptionsDlg(int tab, CWnd* pParent /*=NULL*/)
	: CBaseDialog(IDD_OPTIONS_DIALOG, pParent), m_tab_selected{ tab }
{

}

COptionsDlg::~COptionsDlg()
{
}

CString COptionsDlg::GetDialogName() const
{
	return _T("OptionsDlg");
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(COptionsDlg, CBaseDialog)
    ON_WM_SIZE()
END_MESSAGE_MAP()


// COptionsDlg ��Ϣ�������


BOOL COptionsDlg::OnInitDialog()
{
	CBaseDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	theApp.m_option_dlg = m_hWnd;

	SetWindowText(CCommon::LoadText(IDS_TITLE_OPTION));
    SetIcon(theApp.GetMenuIcon(IDI_SETTINGS), FALSE);		// ����Сͼ��

	//�����ӶԻ���
	m_tab1_dlg.Create(IDD_MAIN_WND_SETTINGS_DIALOG, &m_tab);
	m_tab2_dlg.Create(IDD_TASKBAR_SETTINGS_DIALOG, &m_tab);
	m_tab3_dlg.Create(IDD_GENERAL_SETTINGS_DIALOG, &m_tab);

    //�����ӶԻ���
    m_tab_vect.push_back(&m_tab1_dlg);
    m_tab_vect.push_back(&m_tab2_dlg);
    m_tab_vect.push_back(&m_tab3_dlg);

    //��ȡ�ӶԻ���ĳ�ʼ�߶�
    for (const auto* pDlg : m_tab_vect)
    {
        CRect rect;
        pDlg->GetWindowRect(rect);
        m_tab_height.push_back(rect.Height());
    }

	//��ӶԻ���
	m_tab.AddWindow(&m_tab1_dlg, CCommon::LoadText(IDS_MAIN_WINDOW_SETTINGS));
	m_tab.AddWindow(&m_tab2_dlg, CCommon::LoadText(IDS_TASKBAR_WINDOW_SETTINGS));
	m_tab.AddWindow(&m_tab3_dlg, CCommon::LoadText(IDS_GENERAL_SETTINGS));

    //Ϊÿ���Ӵ������ù�����Ϣ
    for (size_t i = 0; i < m_tab_vect.size(); i++)
    {
        m_tab_vect[i]->SetScrollbarInfo(m_tab.m_tab_rect.Height(), m_tab_height[i]);
    }

	//����Ĭ��ѡ�еı�ǩ
    if (m_tab_selected < 0 || m_tab_selected >= m_tab.GetItemCount())
        m_tab_selected = 0;
    m_tab.SetCurTab(m_tab_selected);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void COptionsDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_tab1_dlg.OnOK();
	m_tab2_dlg.OnOK();
	m_tab3_dlg.OnOK();

	CBaseDialog::OnOK();
}


void COptionsDlg::OnSize(UINT nType, int cx, int cy)
{
    CBaseDialog::OnSize(nType, cx, cy);

    // TODO: �ڴ˴������Ϣ����������
    if (nType != SIZE_MINIMIZED)
    {
        //Ϊÿ���Ӵ������ù�����Ϣ
        for (size_t i = 0; i < m_tab_vect.size(); i++)
        {
            m_tab_vect[i]->ResetScroll();
            m_tab_vect[i]->SetScrollbarInfo(m_tab.m_tab_rect.Height(), m_tab_height[i]);
        }
    }
}
