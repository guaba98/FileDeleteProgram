
// FileDeleteProgramDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FileDeleteProgram.h"
#include "FileDeleteProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileDeleteProgramDlg 대화 상자



CFileDeleteProgramDlg::CFileDeleteProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILEDELETEPROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileDeleteProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DEL_PATH, m_ctrlDelPathList);
	DDX_Control(pDX, IDC_EDIT_PATH, m_EditAddPath);
}

BEGIN_MESSAGE_MAP(CFileDeleteProgramDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SET_PATH, &CFileDeleteProgramDlg::OnBnClickedBtnSetPath)
	ON_BN_CLICKED(IDC_BTN_ADD_PATH, &CFileDeleteProgramDlg::OnBnClickedBtnAddPath)
	ON_BN_CLICKED(IDC_BTN_SET_COPY_PATH, &CFileDeleteProgramDlg::OnBnClickedBtnSetCopyPath)
	ON_BN_CLICKED(IDC_BTN_SAVE_CLOSE, &CFileDeleteProgramDlg::OnBnClickedBtnSaveClose)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DEL_PATH, &CFileDeleteProgramDlg::OnNMDblclkListDelPath)
END_MESSAGE_MAP()


// CFileDeleteProgramDlg 메시지 처리기

BOOL CFileDeleteProgramDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFileDeleteProgramDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileDeleteProgramDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFileDeleteProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 삭제할 폴더 경로 탐색
void CFileDeleteProgramDlg::OnBnClickedBtnSetPath()
{
	// 초기 선택 폴더
	CString strInitPath = _T("C:\\");
	CString strLog;
	// 폴더 선택 다이얼로그
	CFolderPickerDialog Picker(strInitPath, OFN_FILEMUSTEXIST, NULL, 0);
	if (Picker.DoModal() == IDOK)
	{
		// 선택된 폴더 경로얻음
		m_strFolderPath = Picker.GetPathName();

		GetDlgItem(IDC_EDIT_PATH)->SetWindowText(m_strFolderPath);
	}
}

// 삭제할 폴더 경로 추가
void CFileDeleteProgramDlg::OnBnClickedBtnAddPath()
{
	// 경로 가져오기
	CString strAddPath;
	m_EditAddPath.GetWindowTextW(strAddPath);

	// 비어있지 않은 경우만 추가
	if (!strAddPath.IsEmpty())
	{
		// 리스트 컨트롤에 값 추가
		int nIndex = m_ctrlDelPathList.InsertItem(m_ctrlDelPathList.GetItemCount(), strAddPath);

		// Cstring 배열에 값 추가
		arr.push_back(strAddPath);

		// text edit control에 값 삭제
		m_EditAddPath.SetWindowTextW(_T(""));

	}

	UpdateData(FALSE);
	
	
}

// 복사할 경로 설정
void CFileDeleteProgramDlg::OnBnClickedBtnSetCopyPath()
{
	
}


// 저장하고 닫기 
void CFileDeleteProgramDlg::OnBnClickedBtnSaveClose()
{
	
}

// 더블클릭시 리스트컨트롤에서 해당 아이템 삭제
void CFileDeleteProgramDlg::OnNMDblclkListDelPath(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	// 우클릭한 아이템 삭제
	int nItem = m_ctrlDelPathList.GetNextItem(-1, LVNI_SELECTED);
	if (nItem != -1)
	{
		m_ctrlDelPathList.DeleteItem(nItem);

		// CString 배열에서 값 삭제
		arr.erase(arr.begin() + nItem);
	}
	*pResult = 0;
}
