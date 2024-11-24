﻿#pragma once
#include "afxdialogex.h"
#include "MainFrm.h"
#include "pch.h"

// CChatRoom 대화 상자

class CChatRoom : public CDialogEx
{
	DECLARE_DYNAMIC(CChatRoom)

public:
	CChatRoom(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CChatRoom();

	CSocServer m_socServer;
	CSocCom* m_socCom[MAX_CLIENT_COUNT];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHATROOM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CButton m_sendbutton;
	CEdit m_edit_send;
	CListBox m_List_chating;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSend();
	afx_msg LPARAM OnAccept(WPARAM wParam, LPARAM lParam);
	afx_msg LPARAM OnReceive(WPARAM wParam, LPARAM lParam);
	CString m_strStatus;
	std::list<int> m_using;
	CString m_strSend;
};
