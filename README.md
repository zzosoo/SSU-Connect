# SSU-Connect
# 2024-11-04 일정 수립, 초기화면 구성, 데이터베이스 설정
1주차
-DB구성, 로그인 기능, 화면 구성

2주차
-친구, 채팅방 기능

3주차
-수정 및 보완

# 2024-11-10 

## DB
인스턴스 연결에 성공하였으나
지속적으로 메모리 할당 오류 발생
(bad_alloc)
라이브러리를 로드하기 위한 파일이 작업 환경에
존재하지 않아 발생했다고 생각하여 적절한 파일들을
실행파일이 존재하는 파일로 옮기고, 링커와 종속성 설정을
진행함. 그러나 메모리 할당 오류 해결되지 않음.

mfc에서 데이터베이스로 데이터 전송이 불가능한 상황,

https://m.blog.naver.com/tipsware/222073613408
해당 블로그의 방식대로 진행

32비트 기준으로 설명되어있어 64비트 환경에서 연결하는데 문제 발생
ODBC드라이버를 다운로드 할 때 자동으로 9.0버전이 받아지는데, 
mysql 8.x버전과 호환이 안되는 것을 파악. 8.x버전으로 다시 설치.
8.x 버전을 사용하여 문제 해결. 

데이터베이스와 연결 성공. 

## UI
윈도우 크기 고정 및 버튼 배치 과정 수행.
상단 내비게이션 바와 하단 버튼 구역 나누는 과정 수행.

UI에서 버튼을 누르면 메인 뷰의 화면을 바꾸도록 OnPaint()함수 수정 및 RemoveView()라는 함수를 만듬으로써 구현
RemoveView()를 하면 뷰의 상태를 바꾸고, 모든 상태에서도 존재하는 Logout버튼은 위치만 이동시키고 다른 버튼은 지우도록 하는 식으로 구현

특이사항 : 
초기시작 했을 때 윈도우가 두개가 뜨는 오류가 있었음
-> .cpp 파일에 initinstance()함수에서 CSingleDocTemplate가 문서-뷰 구조를 강제로 생성하기 때문이었음
이를 위해 CSingleDocTemplate 관련 부분을 제거하고 CMainFrame만 생성하도록 InitInstance 함수를 수정했음.
문서-뷰 구조 제거: CSingleDocTemplate와 AddDocTemplate(pDocTemplate); 관련 코드 삭제.
프레임 창만 생성: CMainFrame을 생성하여 m_pMainWnd에 할당하고 이를 메인 창으로 설정.

# 2024-11-11 

## DB
데이터베이스 접속불가

# 2024-11-15 

## DB
데이버베이스 접속 및 연결 성공
https://blog.naver.com/aiesko/20131995728
https://blog.naver.com/dd1587/221157117516
이 두 블로그를 참고하여 진행

중간 중간 생기는 오류는 디버깅을 통해 쿼리나, 커넥터에 올바르지 않은 값이 들어가 있는 것을 확인
각 함수의 매개 변수를 확인하여 올바르지 않는 변수가 할당되어 있다는 것을 알게 되었음

이후 디버깅을 통해 쿼리에서 정확한 값이 들어오는 것을 확인했으나 글자가 깨지는 현상이 발생
%s -> %S 로 인자를 바꿔주어서 해결

여전히 한글이 깨져서 나오는 문제가 있음

# 2024-11-17
UI가 만들어져있는 파일에 데이터베이스 연결 성공

역할 재분배 -서버, 회원정보, 채팅방

오픈채팅방 형식으로 변경

프로그램상에서 데이터베이스에 query 전송 가능

## 채팅방
프로그램상에서 데이터베이스에 table 생성 기능 구현
하나의 table이 하나의 채팅방

## 로그인
데이터베이스와 프로그램 연결 구현
로그인 기능과 회원가입 기능 구현 완료

# 2024-11-18

## 채팅방
채팅방 생성, 접속, 채팅 보내기 기능 구현 완료
## 설정탭
회원정보 변경, 회원탈퇴 기능 구현 완료
## 서버
IP 주소를 통해서 같은 네트워크 안에 있는 컴퓨터끼리 통신 구현
한글 깨짐 현상 수정 (컴파일 형식을 UTF-8로 하도록 코드 상에서 수정)
서버와 클라이언트를 나눔
서버가 여러 클라이언트를 받고 각 클라이언트에 대한 식별 코드 부여

# 2024-11-24
기존 프로그램에 서버 연결 코드 이식
서버는 MFC 자체 소켓 이용해서 구현

## UI
메인프레임 상에 채팅방, 사용자 목록 리스트 구현

## 주요 이슈
기존 코드를 서버용과 클라이언트용으로 구분하여 작성하지 못했고, 이에 따라 서버를 연결하는 과정에서 기존 클라이언트 코드를 대폭 수정해야하는 이슈 발생
deadline이 1주일 남은 상황에서 클라이언트 코드를 재구현하는 것이 불가능하다고 판단, 서버용 코드를 하나의 컴퓨터에서 구현하는 방식 채택
위의 방식으로 프로젝트 구현에 성공하면, 데이터베이스를 공유하는 방법을 추가로 활용하여 둘 이상의 컴퓨터에서 실행하는 방식 시도할 예정

# 2024-11-24

## 변경사항
주석 추가 및 불필요한 코드 삭제

## 최종
보고서 및 발표자료 작성, 프로젝트 제출
