
// FileDeleteProgramDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <vector>


// CFileDeleteProgramDlg 대화 상자
class CFileDeleteProgramDlg : public CDialogEx
{
// 생성입니다.
public:
	CFileDeleteProgramDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEDELETEPROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
	std::vector<CString> arr; // 값을 저장할 CString 배열
	afx_msg void OnNMDblclkListDelPath(NMHDR *pNMHDR, LRESULT *pResult);
};
