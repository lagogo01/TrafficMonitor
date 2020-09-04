#pragma once
#include "afxwin.h"
#include"StaticEx.h"
#include "PictureStatic.h"
#include "CSkinPreviewView.h"
#include "LinkStatic.h"
#include "BaseDialog.h"

// CSkinDlg �Ի���

class CSkinDlg : public CBaseDialog
{
	DECLARE_DYNAMIC(CSkinDlg)

public:
	CSkinDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSkinDlg();

	vector<wstring> m_skins;		//Ƥ���ļ���·��
	int m_skin_selected;			//ѡ���Ƥ��
	CFont* m_pFont;		//Ԥ��ͼ������

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SKIN_DIALOG };
#endif

	//COLORREF GetTextColor() const { return m_skin_data.text_color; }
	//DispStrings GetDispStrings() const { return m_skin_data.disp_str; }
	const SkinData& GetSkinData() const { return m_skin_data; }
	static void LoadSkinLayout(const wstring& cfg_path, LayoutData& layout_data);

protected:
	virtual CString GetDialogName() const override;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

protected:
	//�ؼ�����
	CComboBox m_select_box;			//ѡ���
	CLinkStatic m_skin_course;	//��Ƥ�������̡̳�������
	CLinkStatic m_skin_download;	//������Ƥ�����ء�������
	CSkinPreviewView* m_view;	//Ԥ������ͼ��
	CStatic m_preview_static;
	CStaticEx m_notify_static;	//��ʾ��ʾ��Ϣ��static�ؼ�

	SkinData m_skin_data;		//Ƥ������
	CImage m_background_s;		//СԤ��ͼ����ͼ
	CImage m_background_l;		//��Ԥ��ͼ����ͼ

	void ShowPreview();		//��ʾƤ��Ԥ��
	void LoadBackImage(const wstring& path, bool small_image);		//���뱳��ͼ��pathΪƤ������·����small_imageָ������С����ͼ���Ǵ󱳾�ͼ
	CRect CalculateViewRect();		//���ݴ��ڴ�С����Ԥ����ͼ�Ĵ�С

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
