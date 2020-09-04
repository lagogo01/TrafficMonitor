#pragma once
#include "TabDlg.h"
#include "SpinEdit.h"

// CGeneralSettingsDlg dialog

class CGeneralSettingsDlg : public CTabDlg
{
	DECLARE_DYNAMIC(CGeneralSettingsDlg)

public:
	CGeneralSettingsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGeneralSettingsDlg();

	//ѡ����������
	GeneralSettingData m_data;

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GENERAL_SETTINGS_DIALOG };
#endif

public:
	bool IsAutoRunModified() const { return m_auto_run_modified; }
	bool IsShowAllInterfaceModified() const { return m_show_all_interface_modified; }
    bool IsMonitorTimeSpanModified() const;

protected:
	bool m_auto_run_modified{ false };		//��������˿����Զ����е����ã������Ϊtrue
	bool m_show_all_interface_modified{ false };
    int m_monitor_time_span_ori{};

	//�ؼ�����
	CSpinEdit m_traffic_tip_edit;
	CComboBox m_traffic_tip_combo;
	CSpinEdit m_memory_tip_edit;
	CComboBox m_language_combo;
	CToolTipCtrl m_toolTip;
    CSpinEdit m_monitor_span_edit;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//���ÿؼ������úͽ���
	void SetTrafficTipControlEnable(bool enable);
	void SetMemoryTipControlEnable(bool enable);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheckNowButton();
	afx_msg void OnBnClickedCheckUpdateCheck();
	afx_msg void OnBnClickedAutoRunCheck();
	afx_msg void OnBnClickedAllowSkinFontCheck();
	afx_msg void OnBnClickedAllowSkinDispStrCheck();
	virtual void OnOK();
	afx_msg void OnBnClickedTodayTrafficTipCheck();
	afx_msg void OnBnClickedMemoryUsageTipCheck();
	afx_msg void OnBnClickedOpenConfigPathButton();
	afx_msg void OnBnClickedShowAllConnectionCheck();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedUseCpuTimeRadio();
	afx_msg void OnBnClickedUsePdhRadio();
    afx_msg void OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnEnKillfocusMonitorSpanEdit();
};
