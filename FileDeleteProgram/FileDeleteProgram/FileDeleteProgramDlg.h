
// FileDeleteProgramDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <vector>


// CFileDeleteProgramDlg ��ȭ ����
class CFileDeleteProgramDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFileDeleteProgramDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEDELETEPROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSetPath();
	afx_msg void OnBnClickedBtnAddPath();
	afx_msg void OnBnClickedBtnSetCopyPath();
	afx_msg void OnBnClickedBtnSaveClose();

	CString m_strFolderPath;
	CListCtrl m_ctrlDelPathList;
	CEdit m_EditAddPath;
	std::vector<CString> arr; // ���� ������ CString �迭
	afx_msg void OnNMDblclkListDelPath(NMHDR *pNMHDR, LRESULT *pResult);
};
