﻿// CSocCom.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication4.h"
#include "CSocCom.h"


// CSocCom

CSocCom::CSocCom()
{
}

CSocCom::~CSocCom()
{
}

void CSocCom::Init(HWND hWnd) {
	m_hWnd = hWnd;
}
// CSocCom 멤버 함수


void CSocCom::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	SendMessage(m_hWnd, UM_RECEIVE, m_index, 0);

	CSocket::OnReceive(nErrorCode);
}
