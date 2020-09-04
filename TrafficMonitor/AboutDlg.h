#pragma once
#include "DonateDlg.h"
#include "LinkStatic.h"

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// �Ի�������

protected:
	CLinkStatic m_mail;				//����ϵ���ߡ�������
	CLinkStatic m_acknowledgement;	//����л��������
	CLinkStatic m_github;			//��GitHub��������
	CLinkStatic m_donate;			//��������������
	CLinkStatic m_license;			//����ԴЭ�顱������
	CToolTipCtrl m_tool_tip;			//���ָ��ʱ�Ĺ�����ʾ
	CLinkStatic m_translaotr_static;

    CRect m_rc_pic;     //ͼƬ��λ��
    CBitmap m_about_pic;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CString GetDonateList();		//����Դ�ļ����ؾ�����Ա����

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//	afx_msg void OnStnClickedStaticDonate();
protected:
	afx_msg LRESULT OnLinkClicked(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnPaint();
};
