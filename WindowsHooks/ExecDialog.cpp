// ExecDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "WindowsHooks.h"
#include "ExecDialog.h"
#include "afxdialogex.h"


// ExecDialog 对话框

IMPLEMENT_DYNAMIC(ExecDialog, CDialogEx)

ExecDialog::ExecDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Exec, pParent)
{

}

ExecDialog::~ExecDialog()
{
}

void ExecDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_ProgramName);
}


BEGIN_MESSAGE_MAP(ExecDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &ExecDialog::OnBnClickedOk)
//	ON_WM_ACTIVATE()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// ExecDialog 消息处理程序


void ExecDialog::OnBnClickedOk()
{	
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	edit_ProgramName.GetWindowTextW(m_strProgrameName, 200);
	CDialogEx::OnOK();
}


//void ExecDialog::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//	edit_ProgramName.SetFocus();
//	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
//}


void ExecDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	edit_ProgramName.SetFocus();
	CDialogEx::OnShowWindow(bShow, nStatus);
}
