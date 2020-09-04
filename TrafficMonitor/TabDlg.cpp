#include "stdafx.h"
#include "TabDlg.h"
#include "TrafficMonitor.h"

IMPLEMENT_DYNAMIC(CTabDlg, CDialogEx)

CTabDlg::CTabDlg(UINT nIDTemplate, CWnd * pParent) : CDialogEx(nIDTemplate, pParent)
{
	m_pParent = pParent;
}


CTabDlg::~CTabDlg()
{
}


BOOL CTabDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
    //��������tab��ǩ�е��ӶԻ�������û����س���ESC��Ӧ����Ӧ��ǰ�Ի����IDOK��IDCANCEL��
    //��Ӧ����Ӧtab��ǩ�ĸ����ڵ�IDOK��IDCANCEL����
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		if (m_pParent != nullptr)
			m_pParent->SendMessage(WM_COMMAND, IDCANCEL);
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (m_pParent != nullptr)
			m_pParent->SendMessage(WM_COMMAND, IDOK);
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CTabDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//�����ڱ������óɰ�ɫ
	SetBackgroundColor(RGB(255, 255, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

CWnd* CTabDlg::GetParentWindow()
{
    CWnd* pParent = GetParent();
    if (pParent != nullptr)
    {
        return pParent->GetParent();
    }
    return nullptr;
}

void CTabDlg::SetScrollbarInfo(int nPage, int nMax)
{
	if(m_scroll_enable)
	{
		//��ʼ��������
		SCROLLINFO scrollinfo;
		GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		scrollinfo.nPage = nPage;    //���û����С
		scrollinfo.nMin = 0;
		scrollinfo.nMax = nMax;     //���ù����������λ��
		if (scrollinfo.nMax < 0)
			scrollinfo.nMax = 0;
		scrollinfo.nPos = scrollinfo.nMin;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	}
}

void CTabDlg::ResetScroll()
{
	if (m_scroll_enable)
	{
		SCROLLINFO scrollinfo;
		GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		int step = scrollinfo.nPos - scrollinfo.nMin;
		scrollinfo.nPos = scrollinfo.nMin;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, step);
	}
}

void CTabDlg::ScrollWindowSimple(int step)
{
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	scrollinfo.nPos -= step;
	if (scrollinfo.nPos < scrollinfo.nMin)
	{
		step = scrollinfo.nPos + step - scrollinfo.nMin;		//������Ϲ���һ�������С�ڹ���������Сλ���ˣ�������step��ֵ��ʹ���ڹ��������Ϸ�
		scrollinfo.nPos = scrollinfo.nMin;
	}
	if (scrollinfo.nPos + scrollinfo.nPage > scrollinfo.nMax)  //�˴�һ��Ҫע����ϻ���ĳ��ȣ������ж�
	{
		step -= (scrollinfo.nMax - (scrollinfo.nPos + scrollinfo.nPage));		//������Ϲ���һ���������ڹ����������λ���ˣ�������step��ֵ��ʹ���ڹ��������·�
		if (step > 0)
			step = 0;
		scrollinfo.nPos = scrollinfo.nMax;
	}
	SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	ScrollWindow(0, step);

}

BEGIN_MESSAGE_MAP(CTabDlg, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


void CTabDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�ο����ϣ�https://www.cnblogs.com/ranjiewen/p/6013922.html

	if (m_scroll_enable)
	{
		SCROLLINFO scrollinfo;
		GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		int unit = 1;
		int step = theApp.DPI(16);
		switch (nSBCode)
		{
		case SB_LINEUP:          //Scroll one line up
			ScrollWindowSimple(unit * step);
			break;
		case SB_LINEDOWN:           //Scroll one line down
			ScrollWindowSimple(-unit * step);
			break;
		case SB_PAGEUP:            //Scroll one page up.
			ScrollWindowSimple(unit * step * 5);
			break;
		case SB_PAGEDOWN:        //Scroll one page down        
			ScrollWindowSimple(-unit * step * 5);
			break;
		case SB_ENDSCROLL:      //End scroll     
			break;
		case SB_THUMBPOSITION:  //Scroll to the absolute position. The current position is provided in nPos
			break;
		case SB_THUMBTRACK:                  //Drag scroll box to specified position. The current position is provided in nPos
			ScrollWindow(0, (scrollinfo.nPos - nPos)*unit);
			scrollinfo.nPos = nPos;
			SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
			break;
		}
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CTabDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_scroll_enable)
	{
		int step = theApp.DPI(64);
		if (zDelta > 0)
		{
			ScrollWindowSimple(step);
		}
		if (zDelta < 0)
		{
			ScrollWindowSimple(-step);
		}
	}

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CTabDlg::OnOK()
{
    // TODO: �ڴ����ר�ô����/����û���

    CDialogEx::OnOK();
}
