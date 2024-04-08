
// FileDeleteProgramDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FileDeleteProgram.h"
#include "FileDeleteProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CFileDeleteProgramDlg ��ȭ ����



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


// CFileDeleteProgramDlg �޽��� ó����

BOOL CFileDeleteProgramDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CFileDeleteProgramDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CFileDeleteProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ������ ���� ��� Ž��
void CFileDeleteProgramDlg::OnBnClickedBtnSetPath()
{
	// �ʱ� ���� ����
	CString strInitPath = _T("C:\\");
	CString strLog;
	// ���� ���� ���̾�α�
	CFolderPickerDialog Picker(strInitPath, OFN_FILEMUSTEXIST, NULL, 0);
	if (Picker.DoModal() == IDOK)
	{
		// ���õ� ���� ��ξ���
		m_strFolderPath = Picker.GetPathName();

		GetDlgItem(IDC_EDIT_PATH)->SetWindowText(m_strFolderPath);
	}
}

// ������ ���� ��� �߰�
void CFileDeleteProgramDlg::OnBnClickedBtnAddPath()
{
	// ��� ��������
	CString strAddPath;
	m_EditAddPath.GetWindowTextW(strAddPath);

	// ������� ���� ��츸 �߰�
	if (!strAddPath.IsEmpty())
	{
		// ����Ʈ ��Ʈ�ѿ� �� �߰�
		int nIndex = m_ctrlDelPathList.InsertItem(m_ctrlDelPathList.GetItemCount(), strAddPath);

		// Cstring �迭�� �� �߰�
		arr.push_back(strAddPath);

		// text edit control�� �� ����
		m_EditAddPath.SetWindowTextW(_T(""));

	}

	UpdateData(FALSE);
	
	
}

// ������ ��� ����
void CFileDeleteProgramDlg::OnBnClickedBtnSetCopyPath()
{
	
}


// �����ϰ� �ݱ� 
void CFileDeleteProgramDlg::OnBnClickedBtnSaveClose()
{
	
}

// ����Ŭ���� ����Ʈ��Ʈ�ѿ��� �ش� ������ ����
void CFileDeleteProgramDlg::OnNMDblclkListDelPath(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	// ��Ŭ���� ������ ����
	int nItem = m_ctrlDelPathList.GetNextItem(-1, LVNI_SELECTED);
	if (nItem != -1)
	{
		m_ctrlDelPathList.DeleteItem(nItem);

		// CString �迭���� �� ����
		arr.erase(arr.begin() + nItem);
	}
	*pResult = 0;
}
