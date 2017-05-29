정리 중...

# 1. HTTP/HTTP 2.0  
## 1.1. HTTP  
 Huyper Text Transfer Protocol의 약자로 WWW(World Wide Web)에서 하이퍼텍스트(hypertext) 문자를 교환하기 위하여 사용되는 통신규약.

### 1.1.1. Status code : HTTP 통신 중 요청의 상태 정보 제공
	1. 1xx - Informational - 정보교환
	2. 2xx - Success - 성공
		* 200 - OK	- 요청이 성공적으로 전송됨
	3. 3xx - Redirection - 방향 지정
		* 301 - Moved Permanently - 요청 페이지의 영구적인 위치 변화
		* 302 - Found	- 요청 페이지이 일시적인 위치 변화
	4. 4xx - Client Error - 클라이언트 오류
		* 404 - Not Found - 요청받은 자원을 서버에서 찾을 수 없을때 나타나는 상태 
		* 405 - Method Not Allowed - 서버에서 사용자가 요청한 주소의 메소드를 지원하지 않을때 나타남
	5. 5xx - server Error - 서버 오류

### 1.1.2. Request Method : 
	1. OPTIONS: 요청한 URL에 어떠한 메소드 요청이 가능한지 묻는다.
	2. GET: 다른 작업없이 데이터의 검색에 이용.
	3. HEAD: 데이터의 검색에 이용하나 GET과는 다르게 응답 HEADER만 받는다.
	4. POST: URL에 새로운 데이터를 보낼때 사용.
	5. PUT: URL에 저장될 정보를 보낸다.
	6. DELETE: URL의 리소스를 삭제한다.
	7. TRACE: 보낸 메세지를 다시 돌려받는다.
	8. CONNECT: 프록시에서 사용되는 예약 메소드.
		
## 1.2. HTTP 2.0
 Latency(지연 시간)를 줄여 웹의 속도를 개선하기 위해 등장. 효율적인 페이지 로딩을 위해 URL의 이미지, 스크립트등의 자원을 압축해 페이지 렌더링을 위한 요청횟수를 감소시켰다. 뿐만 아니라 server가 push가 가능해 웹페이지의 렌더링이 필요하단 사실을 알게되면 추가 요청없이 서버가 리소스를 제공한다. 그 외에도 성능 개선을 위한 요청 다중화, 헤더 압축, HOL Blocking해결을 위한 요청 우선순위 결정등이 있다.
 
	1. 특징
		* HTTP Header 데이터 압축
		* Server Push(서버에서 부터 시작되는 전송)
		* HTTP 1에서 존재하던 head-of-line blocking 문제 개선
		* 싱글 TCP connection내에서 병렬 페이지 로딩 구현
		* 2.0은 기존 버전인 1.1과의 높은 호환성(method, status codes 등)은 보장하고 클라이언트 서버 간 전송 및 프레임
		의 개선에 초점을 맞췄다.
		※ head-of-line blocking: 동일한 송신 포트 자원에 대한 처리량 경쟁으로 인해 처리량 지연 및 프레임 손실 발생 
		유발. 작업대기 중인 2개의 패킷이 존재할 경우 첫번째 패킷이 대기중이면 그 뒤 패킷들은 무조건 대기할때 발생.
		
	2. HTTP 2.0과 SPDY
		* SPDY : Google이 ‘speedy’라는 단어를 기반으로 제안한 새로운 프로토콜이다. HTTP의 단점들을 보완하여, 인터넷 
		환경을 보다 효율적으로 이용하기 위한 프로토콜이다. HTTP/2.0에서는 스펙에 SPDY를 반영할 예정이다.
		* 특징
			* TLS 위에서 동작한다. https에서만 적용가능
			* HTTP 헤더를 압축한다. 요청마다 반복되는 내용을 압축해 성능 향상 효과가 나타남
			* 바이너리로 프레임을 구성한다. 파싱 속도가 향상되고 오류확률은 낮아진다.
			* 다중 연결을 지원한다.	다수의 요청, 응답 을 동시에 처리 할 수 있어 속도 향상
			* 인터리빙을 허용한다. 우선순위가 높은 데이터가 더 빨리 전송 될 수있다.
			* 서버 푸시가 가능하다.
		
## 3. 결론
 HTTP 1.1 이 사용하는 전송방식(RFC7230)에는 몇가지 문제점이 존재했다. HTTP/1.0은 TCP connection에서 한번에 하나의 요청 만이 가능했고 HTTP/1.1에서는 그보다 발전하여 request pipelining을 사용했지만 여전히 HOL Blocking 문제가 존재했다. HTTP/2.0은 오랫동안 변화하지 않았던 HTTP를 현 웹 환경에 맞게 발전시켜 속도의 향상을 도모 한다는데 크 의의가 있다.
 
# 2. HTTPS

HTTP에 인증과 안전성을 더해서 안전한 통신을 지원하는 통신 규약(HTTP는 도청, 위장, 변조의 위험이 존재).
새로운 프로토콜이 아니라, HTTP 프로토콜의 소켓을 SSL이나 TLS로 대체하여 TCP로 직접 통신하지 않고 SSL과 통신하게 하여 암호화와 인증서를 이용할 수 있게 한다.

※ SSL : HTTP와 독립된 프로토콜로 어플리케이션 계층에서 동작하는 다른 프로토콜에도 적용이 가능하다.

## 하이브리드 암호 시스템?
HTTPS는 공통키 암호와 공개키 암호의 양쪽 성질을 가진 하이브리드 암호 시스템입니다.
두가지 방식을 조합해서 장점을 살립니다.
키를 교환하는 곳에서는 공개키 암호를 사용하고 그 후의 통신에서 메시지를 교환하는 곳에서는 공통키 암호를 사용합니다.

## 공통키 암호

상호간에 키를 교환하는 암호화 방식을 공개키 암호화 방식이라고 합니다.
SSL에서는 공개키 암호화 방식을 채용하고 있습니다.
암호화, 복호화에 하나의 키를 같이 사용하는 방식입니다.

하지만 키를 누군가 손에 넣으면 누구라도 암호를 해독할 수 있는 문제가 있습니다.

## 공개키 암호

공개키 암호는 공통키 암호의 문제를 해결하기 위해 등장한 방식입니다.
공개키 암호에서는 서로 다른 두 개의 키 페어(쌍)를 사용합니다.
비밀키(private key)와 공개키(public key)가 그것입니다.
비밀키는 알려지면 안되는 키이며, 공개키는 누구에게나 알려져도 괜찮은 키입니다.

1. 암호를 보내는 측(클라이언트)이 상대의 공개키를 사용해 암호화를 합니다.
2. 암호화된 정보를 받아들인 상대(서버)는 자신의 비밀키를 사용해 복호화를 실시합니다.
이 방식은 암호를 푸는 비밀키를 통신으로 보낼 필요가 없으며 도청에 의해서 키를 빼앗길 걱정이 없습니다.

하지만 공개키가 진짜인지 아닌지를 서버에서 증명할 수가 없습니다.
이 문제를 해결하는 데는 인증기관(CA : Certificate Authority)과 그 기관이 발행하는 공개키 증명서가 이용되고 있습니다.
인증 기관이란 클라이언트와 서버 모두 신뢰하는 제 3자 기관입니다.
공개키를 인증 기관에 제출하면 인증 기관은 제출된 공개키에 디지털 서명을 하고 서명이 끝난 공개키를 만듭니다.
그리고 공개키 인증서에 서명이 끝난 공개키를 담습니다.

이런 인증 기관의 공개키는 안전하게 클라이언트에 전달되어야 합니다.
하지만 어떤 방법을 사용하더라도 100% 안전이 보장되지 않기 때문에 많은 브라우저가 인증기관의 공개키를 사전에 내장한 상태로 제품을 내놓고 있습니다.

# 3. TCP / UDP

## 3.1. TCP
		(1) 정의 : 연결형 서비스를 위해 호스트 간 신뢰성 있는 데이터 전달과 흐름제어 및 혼잡제어 등을 
		제공하는 전송계층 프로토콜로 인터넷 환경에서 기본으로 사용된다. 
		
		(2) 특징
			- 가상 회선 연결 방식, 연결형 서비스를 제공
			- 높은 신뢰성(Sequence Number, Ack Number를 통한 신뢰성 보장)
			- 연결의 설정(3-way handshaking)과 해제(4-way handshaking)
			- 데이터 흐름 제어
			(수신자 버퍼 오버플로우 방지) 및 혼잡 제어(네트워크 내 패킷 수가 과도하게 증가하는 현상 방지)
			- 전이중(Full-Duplex), 점대점(Point to Point) 서비스
		
		(3) 소켓 통신 과정
			- 서버 : 소켓을 생성, 주소 할당, 연결 요청 기다림, 요청에 대한 응답
			- 클라이언트 : 소켓을 생성, 주소 할당, 연결 요청		
			
## 3.2. UDP
		(1) 정의 : 비연결형 서비스를 지원하는 전송계층 프로토콜로 정보를 보낸다는 신호나 받는다는 
		신호 절차를 거치지 않고, 일방적으로 데이터를 전달. 

		(2) 특징
			- 비연결형(port만 확인하여 소켓을 식별하고 송수신)
			- 패킷 오버헤드가 적어 네트워크 부하 감소
			- 비신뢰성
			- 오류검출(헤더에 오류 검출 필드를 포함하여 무결성 검사)
			- TCP의 handshaking 같은 연결 설정이 없다
			- DNS, NFS, SNMP, RIP 등 사용

		(3) 소켓통신과정
			- 서버 : 소켓을 생성, 주소 할당, 데이터를 송수신
			- 클라이언트 : 소켓 생성 후 데이터 수신

			UDP는 TCP와 달리 데이터의 수신에 대한 책임을 지지 않는다. 이는 송신자는 정보를 보냈지만, 
			정보가 수신자에게 제때에 도착했는지 또는 정보 내용이 서로 뒤바뀌었는지에 관해서 송신자는 
			상관할 필요가 없다. TCP보다 안정성 면에서는 떨어지지만, 속도는 훨씬 빠르다.
	
# 4. 쿠키/세션

	1. 쿠키/세션이 필요한 이유
		- HTTP 프로토콜은 연결 지향적인 통신이 아니므로 페이지 이동 시 마다 새로운 접속이 이루어지며 이전 
		페이지와 현재 페이지 간의 관계가 지속되지 않는다. 이러한 문제를 해결하기 위해서 쿠키와 세션을 사용한다.
	2. 쿠키
		- Client PC에 저장되어 다른 사용자에 의한 임의 변경 위험이 있다.
		- 생성 이후 서버로 전송되는 요청에는 쿠키 정보가 같이 포함되어 전송
		- 이름, 값, 유효기간, 도메인, 경로 등으로 구성
	3. 세션
		- Session에 관련된 데이터는 Server에 저장된다.
		- 웹 브라우저의 캐시에 저장되어 브라우저가 닫히거나 서버에서 삭제 시 사라진다.
		- Cookie에 비해 보안성이 좋다.
		- 저장 데이터에 제한 없음
		
		
# 5. 소켓서버/웹서버

## 5.1. 소켓서버
### 서버와 클라이언트의 역할
* 서버: 클라이언트의 요청을 처리하고 그 결과를 클라이언트에게 알려주는 역할
* 클라이언트 : 서버에 작업을 요청하고 그결과를 받아서 보여주는 역할

### TCP/IP
* 프로토콜 : 둘 이상의 통신 개체 사이에 교환되는 메시지의 형태, 의미, 전송 순서와 메시지 송수신 및 기타 사전에 수행할 동작을 정의한 규약
프로토콜은 두 개 이상의 호스트 사이에서 데이터를 주고 받는 약속으로 TCP/IP도 프로토콜의 한 종류이다. 

#### OSI 7Layer / TCP 4Layer

### IP
IP는 인터넷 상의 고유 주소이다. IP는 A, B, C, D, E 클래스로 구성되는 데, 각 클래스 별 범위는 다음과 같다.

* A 클래스  | 0.0.0.0 - 127.255.255.255
* B 클래스  | 128.0.0.0 - 191.255.255.255
* C 클래스  | 192.0.0.0 - 233.255.255.255
* D 클래스  | 224.0.0.0 - 239.255.255.255
* E 클래스  | 240.0.0.0 - 255.255.255.255

E 클래스는 나중을 위해 예약되어 있는 클래스, D 클래스는 멀티캐스트를 위한 클래스이다.

### 도메인 주소
여러 IP 주소를 사람이 외워서 사용하기에는 불편하기 때문에 사람이 사용하기 쉬운 도메인 주소를 정의하고 DNS 서비스를 이용하여 IP주소에 이를 매칭하여 사용한다.

### PORT
하나의 컴퓨터에 실행 중인 여러 네트워크 프로그램을 구분하기 위해 부여된 번호이다. 예를 들자면 집을 호스트로 IP를 우편물 주소로 받는 이를 Port로 생각하면 이해하기 쉽다. 1 ~ 1024 는 미리 정의되어 사용되고 있으므로 새로운 서버를 만든다면 이 포트 번호를 피해서 만드는 것이 좋다.

### Loopback
클라이언트와 서버가 같은 호스트에서 TCP/IP를 이용하여 서로 통신할 수 있도록  127.0.0.1 - 127.255.255.255 까지가 루프백 주소로써 localhost라는 이름으로도 할당하고 있다. 브로드캐스트나 멀티캐스트주소로 보내어진 것은 루프백에 복사된 다음 밖으로 나가게 된다.

### MTU
Maximum Transmission Unit - 최대 전송단위로 대부분의 네트워크는 패킷의 상한선이 정해져 있으며 그 보다 클 경우, 분할하여 보낸다. 이것을 단편화(Fragmentation)라 하고 단편화된 패킷은 수신 시 합쳐지게 된다.
※ Path MTU : 두 호스트 사이에 패킷을 전송하는 링크상의 최소 MTU 크기가 Path MTU라 합니다. 만약에 A 와 D가 통신을 한다고 하면 A와 D사이에는 B, C 라는 네트워크가 있다고 해봅시다. A - B - C - D

A의 MTU가 100 B 200 C 70 D 80이라는 MTU를 가지고 있다면 A와 D의 Path MTU는 70이 되는 것입니다.

### TTL
Time-to-live 의 약자로 패킷이 통과할 수 있는 라우터의 수를 제한하기 위해 사용된다. 하나의 라우터를 거칠 때 TTL 값은 1 줄어들고 0이 되면 패킷은 삭제된다. 
※ 게이트웨이 : 서로 다른 네트워크를 연결하는 역할

### TCP 연결 / 연결종료
#### TCP 연결 - 3Way Handshaking
1. 서버 : 클라이언트의 요청을 받을 준비
2. 클라이언트 : 서버에 접속 요청 (SYN)
3. 서버 : 클라이언트에게 클라이언트의 SYN 도착을 알림 (SYN, ACK)
3. 클라이언트 : 서버에게 서버의 SYN 도착을 알림 (ACK)

#### TCP 연결 종료
1. 클라이언트 : 연결 종료를 서버에게 알림 (FIN)
2. 서버 : 클라이언트에게 클라이언트의 FIN이 도착했음을 알림 (FIN/ACK)
3. 클라이언트 : 서버에게 서버의 FIN이 도착했음을 알림 (ACK)

### 소켓 API


### I/O 모델
#### Blocking I/O
소켓을 열면 기본적으로 Blocking I/O mode이다. 서버가 클라이언트로부터 데이터를 받기 위해 recv() 함수를 호출하고 프로세스는 클라이언트로 데이터가 올 때까지 멈춰있는 데 이를 Blocking이라 한다. 간단하고 수행하는 기능이 별로 없는 서버는 Blocking으로 만드는 것이 가능하지만 많은 사용자들이 요청하는 다양한 기능을 처리하는 서버로는 적합하지 않다. 왜냐하면 한 클라이언트에게 데이터를 받기 위해 recv()에서 서버가 멈춰있는다면 서비스 지연 및 서버 활용도를 저해하기 때문이다. 

#### Non-Blocking I/O
Non-Blocking은 요청한 I/O를 처리할 수 있다면 처리하고 처리하지 못한하면 함수를 리턴하여 다른 작업을 할 수 있게 한다. 여기서 I/O를 처리할 수 없어 리턴될 때 다른 오류 코드를 리턴하여 I/O가 이뤄졌는 지 이뤄지지 않았는 지를 확인하여 동작하는 모드가 Non-Blocking mode이다. 
요청한 I/O를 할 수 없다면 클라이언트로부터 데이터를 받을 때까지 확인하는 작업이 필요해진다. 반복적으로 이렇게 데이터를 다 받았는지 확인하는 것을 Polling이라 한다. 이는 CPU 낭비를 초래하므로 클라이언트가 데이터를 보내왔을 때 서버에 데이터를 보내왔다는 것을 알려 준다면, Polling을 하는 것보다 더 좋은 성능을 보여 줄 수 있을 것이다.

#### I/O Multiplexing
입출력 다중화. select() 함수나 poll() 함수를 이용하여 구현한다. 이런 함수들을 이용하여 I/O를 호출하면 실제로는 시스템에서 Blocking되지만 어플리케이션에서는 Blocking 되어 있지 않는다.여러 개의 소켓을 설정하여 그 소켓에 send, recv, error 등을 설정할 수 있다. 그러면 시스템에서 설정된 사항에 맞는 상황 발생 시에 어플리케이션에게 그 사항을 알려준다. 그러면 어플리케이션이 거기에 알맞은 처리를 해준다. 여기서 문제점은 한번에 select() 함수로 설정해 줄 수 있는 소켓 개수에 제한이 있다는 것이다.

#### Signal Driven I/O
인터럽트와 유사한 방법으로 어떤 I/O를 요청하고 그것이 준비되면 어플리케이션에게 신호를 보내 준비되었다는 것을 알려준다. 만약 이러한 방법을 사용한다면 클라이언트에게서 데이터가 들어 왔다면 어플리케이션에게 지정한 신호가 어플리케이션으로 온다는 것이다. 어플리케이션은 신호에 맞게 처리를 해주면 된다. 하지만 이 방법에는 문제가 있는 데 신호가 중복되어 들어온다면 뒤에 온 신호는 무시된다. 그리고 이 방법은 TCP 에는 적당하지 않다고 하는데 TCP 에서는 신호를 설정해두면 수많은 신호들이 어플리케이션에게 온다고 한다. 그리고 신호가 발생되어도 어떤 일이 있었는지 알 수 없다고 한다. 그래서 주로 UDP에서 사용된다.

#### Asynchronaus I/O
Signal Driven I/O 에서는 I/O작업이 시작되는 순간에 신호를 보내어 알려준다. 비동기에서는 I/O작업이 완료되었을 때 이 사실을 알려준다.

많은 방법들이 있는데, Blocking 에서는 block 당하는 것을 해결하려고 non-blocking 이 나오고 non-blocking 의 폴링(polling)을 해결하려는 여러 가지 방법들이 나온 것 같습니다.

유닉스에서는 주로 I/O Multiplexing 을 많이 사용한다고 합니다. 그러나 실제 성능을 테스트해보면 non-blocking 이 가장 좋은 성능을 낸다고 합니다. 그런데 non-blocking 은 적성이 힘들고, 유지보수가 힘들다고 합니다. 그래서 I/O Multiplexing 을 사용하라고 권장하는 것 같습니다.

요즘에는 kqueue 가 BSD 계열 유닉스에서는 그것이 가장 좋은 성능을 낸다고 하고 윈도우에는 IOCP(I/O complete port)가 좋은 성능을 낸다고 합니다. 그러면 이런 좋은 성능을 내는 것만 사용하면 되지 않을까요? 그런 건 아닌 것 같습니다. 그 서버의 역할에 맞는 I/O 모델을 사용하는 것이 가장 효율적일 것입니다. Blocking 으로 충분히 감당할 수 있는 서버인데 무리해서 다른 모델을 도입하는 것은 개발 속도와 유지보수 면에서 불리한 면이 있을 수 있습니다. 그리고 서버의 여러 가지 설계, 그런 부분에서 해당 서버에 잘 맞는 I/O 모델을 선택해서 쓰면 되겠지요.

#### POSIX Thread


[1](http://www.gpgstudy.com/gpgiki/%EC%86%8C%EC%BC%93_%EA%B0%95%EC%A2%8C)  
## 5.2. 웹서버
[1](http://sungbine.github.io/tech/post/2015/02/15/tomcat%EA%B3%BC%20apache%EC%9D%98%20%EC%97%B0%EB%8F%99.html)  
[2](https://okky.kr/article/243427)  
[3](https://github.com/lesstif/web-service-hardening/blob/master/web-server.md)  
[4](http://round1tko.tistory.com/64)  
	
# 6. IOCP

 IOCP는 Input/Output Completion Port의 약자로 입력과 출력의 완료를 담당할 포트를 지정해서 처리하겠다는 의미이다. 입력과 출력의 완료시점에서의 통지는 overlapped(중첩 입출력)에서 처리가 되므로, 이 기술은 윈도의 중첩 입출력 기술을 확장시킨 것으로 볼 수 있다.
포트는 작업 혹은 서비스를 전담하기 위해서 만들어지는 객체다. 소켓의 포트가 특정 서비스로 데이터 입출력을 전달하기 위한 객체임을 상기하면 이해가 쉬울 것이다. 이러한 포트의 특징을 이해하면, 입출력 완료 시점에서 이에 대한 통지를 전담할 포트를 만들어서 데이터를 처리하는 방식도 충분히 생각해 볼 수 있을 것이다.
[1](https://www.joinc.co.kr/w/Site/win_network_prog/doc/iocp)  
[2](http://ozt88.tistory.com/23)  
 
# 7. 하둡

 대량의 자료를 처리할 수 있는 큰 컴퓨터 클러스터에서 동작하는 분산 응용 프로그램을 지원하는 프리웨어 자바 소프트웨어 프레임워크이다.
 [1](http://www.itworld.co.kr/print/73626)  
 
# 8. jquery / bootstrap / ajax

## 8.1. javascript
자바스크립트는 ECMAScript 표준 명세를 따라 구현된 객체 기반 스크립트 프로그래밍 언어이다. HTML 태그 또는 엘리먼트라고 불리는 DOM(Document Object Model)과 BOM(Browser Object Model)을 조작하거나, SPA(Single Page Application)에서 서버와 Ajax 통신을 하는 용도로 주로 사용된다.
[1](https://github.com/nhnent/fe.javascript/wiki/%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0)  
	
## 2. jquery
자바스크립트의 생산성을 향상시켜주는 자바스크립트 라이브러리
	
## 3. bootstrap
트위터에서 시작된 HTML5 기반의 오픈 소스 웹 디자인 프레임워크
		
## 4. ajax
Web에서 화면을 갱신하지 않고 Server로 부터 Data를 가져오는 방법
### 4.1. 동작원리
Ajax의 동작원리는 Browser에서 서버로 보낼 Data를 Ajax Engine을 통해 Server로 전송합니다. 이 때 Ajax Engine에서는 JavaScript를 통해 DOM을 사용하여 XMLHttpRequest(XHR) 객체로 Data를 전달합니다. 이 XHR을 이용해서 Server에서 비동기 방식으로 자료를 조회해 올 수 있습니다. Server에서 Data를 전달 할 때 화면전체의 HTML을 전달하지 않고 Text 또는 Xml형식으로 Browser에 전달합니다.
### 4.2. 사용방법
Ajax의 기본 Method를 이용해서 Server와 통신하려면 XMLHttpRequest를 직접 사용하기 때문에 상당히 복잡하다. 하지만 jQuery를 이용하면 간단히 구현할 수 있다.
	// jQuery를 이용한 Ajax 기본 사용방법입니다.
	$.ajax({
		// URL은 필수 요소이므로 반드시 구현해야 하는 Property입니다.
		url : '요청 URL 주소를 입력합니다.'
		// 다양한 속성들 중에서 필요한 Option을 선택해서 구현합니다.('[]'는 반복해서 사용할 수 있다는 의미입니다.)
		[, Options]
	});

#### 4.2.1. Ajax 통신에 필요한 Property

* url : 요청 전송 URL
* type : HTTP 요청 방식 (GET/POST)
* timeout : 요청 제한 시간
* success : 요청 성공 시 이벤트 핸들러
* error : 요청 실패 시 이벤트 핸들러
* complete : 요청 완료 시 이벤트 핸들러
* data : 요청 후 Return 값
* dataType : 요청 후 Return 값의 Data type(xml, html, script, json, jsonp, text)
* async : 요청 시 동기 유무(True/False)
* cache : 페이지 캐시
* beforeSend : 요청 전 이벤트 핸들러
* global : 전역함수 활성 여부 (True/False)  

[1](http://www.nextree.co.kr/p4771/)  
	
# 9. 웹앱

 브라우저를 이용한 HTML, CSS, 자바스크립트를 사용해 만들어진 어플리케이션으로 인터넷 서비스도 이에 포함된다. 
 [1](http://d2.naver.com/helloworld/179084)  
 
 
# 10. aws (ec2 / elastic search / dynamodb/lambda)

## 10.1. EC2 : EC2(Elastic Compute Cloud)는 AWS 클라우드에서 확장식 컴퓨팅을 제공한다. 
[1](http://docs.aws.amazon.com/ko_kr/AWSEC2/latest/UserGuide/concepts.html)  

## 10.2.) Elastic Search : 아파치 루씬을 기반으로 개발된 오픈소스 분산검색엔진
[1](http://d2.naver.com/helloworld/273788)  
[2](http://opennote46.tistory.com/143)  
[3](http://elasticsearch.tistory.com/entry/elasticsearch%EB%9E%80)  
[루씬](http://killsia.tistory.com/443)  

## 10.3. DynamoDB
[1](https://yangbongsoo.gitbooks.io/study/content/dynamodb2.html)  
[2](https://www.slideshare.net/awskr/dynamodb-42890664+&cd=5&hl=ko&ct=clnk&gl=kr)  
[3](http://docs.aws.amazon.com/ko_kr/amazondynamodb/latest/developerguide/Introduction.html)  

## 10.4. Lambda
[1](http://gun0912.tistory.com/59)  
[2](http://gun0912.tistory.com/60)  
[3](https://aws.amazon.com/ko/blogs/korea/category/aws-lambda/)  
[4](https://www.slideshare.net/awskorea/aws-lambda-100-sangpil-kim)  

# 11. python / flask / sphinx

## 11.1. Python
[1](https://wikidocs.net/6)  

## 11.2. Flask
[1](https://spoqa.github.io/2012/01/16/wsgi-and-flask.html)  
[2](https://code.tutsplus.com/ko/tutorials/an-introduction-to-pythons-flask-framework--net-28822)  

## 11.3. Sphinx
[1](http://sacstory.tistory.com/entry/Debian-%EA%B2%80%EC%83%89-%EC%97%94%EC%A7%84-Sphinx-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0)  
[2](http://crystalcube.co.kr/165)  
[3](http://wiki.pchero21.com/wiki/Sphinx)  
	
# 12. nginx / apache

## 12.1. Nginx
[1](https://opentutorials.org/module/384/3462)  
[2](http://d2.naver.com/helloworld/192785)  
[3](https://openwiki.kr/tech/nginx)  
[4](http://www.haruair.com/blog/1900)  

## 12.2. Apache
[1](https://wiki.archlinux.org/index.php/Apache_HTTP_Server_(%ED%95%9C%EA%B5%AD%EC%96%B4)  
[2](http://cs.sch.ac.kr/lecture/Embedd/06-CompSys-8-Apache.pdf)  

# 13. mysql / mariadb

## 13.1. Mysql
[1](https://wiki.gentoo.org/wiki/MySQL/Startup_Guide/ko)  
Mysql 퍼포먼스 최적화

## 13.2. MariaDB
[1](https://mariadb.com/kb/ko/mariadb/)  

# 14. rabbitmq / redis

## 14.1. RabbitMQ
[1](http://blog.saltfactory.net/install-rabbitmq/)  
[2](http://bcho.tistory.com/786)  
[3](http://abh0518.net/tok/?p=384)  
[4](https://github.com/gjchoi/gjchoi.github.io/blob/master/_posts/2016-02-27-rabbit-mq-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0.md)  
[5](http://hamait.tistory.com/401)  
[6](http://blog.hkwon.me/rabbitmq-php-node-jsreul-hwalyonghae-gcm-push-ceorihagi/)  

## 14.2. Redis
[1](http://tech.kakao.com/2016/03/11/redis-scan/)  
[2](http://bcho.tistory.com/654)  
[3](http://kerocat.tistory.com/1)  
[4](http://d2.naver.com/helloworld/614607)  
	
	
# 15. json query

	
# 16. monitoring / alert

## 16.1. Monitoring / Alert
[1](http://blurblah.net/1474)  
[2](http://mysqldbadmtech.blogspot.kr/2016/12/pmm-170-mysql-alert.html)  
[3](http://tech.whatap.io/2017/04/21/twitter_monitoring_and_alert-system/)  
[4](https://geunhokhim.wordpress.com/2017/01/02/grafana-influxdb-telegraf-monitoring-server-alerting-automation/)  
[5](http://tech.kakao.com/2016/08/25/kemi/)  
[6](https://engineering.linecorp.com/ko/blog/detail/147)  
[7](https://blog.outsider.ne.kr/1254)  
	

# 17. 최근 관심 분야

함수형 프로그래밍에 관심이 있다. 함수형 프로그래밍이 객체지향형 프로그래밍을 대체할 것이라는 말을 들어서 진짜 그게 가능할까하고 훑어봤는데, 그 동안 생각하지 못했던 요소들이 많아서 사고력을 키우는 차원에서 관심을 가지고 학습하려고 합니다.

예를 들어 러스트라는 함수형 프로그래밍언어는 기본 변수 타입이 상수이고 변수를 사용하기 위해서는 별도로 지정해야한다고 해서 설계한 의도가 무엇일까 생각했던 것이 생각난다.

아마도 명확한 코드를 지향해서 그런 것이라 판단했다.


# 18. 보고 있는 책(공부하고 있는 분야)


***
# 19. 객체지향

* 데이터를 객체로 취급하여 객체 간의 상호작용을 통해 프로그램이 동작하게 하는 설계 기법
* 코드 재사용성이 높다.
* 코드의 변경이 쉽다.
 *코드 분석이 쉽다.
 *객체지향 원칙을 사용하여(캡슐화, 상속, 다형성) 개발속도가 빨라진다.

# 20. Object

객체는 객체지향프로그래밍에서 데이터와 그 데이터에 관련되는 동작, 모두가 포함되는 개념
	
# 21. Overloading과 Overriding

* Overloading 같은 이름의 메소드를 여러 개 정의된 메소드의 매개변수는 타입이나 개수가 다름 return type과 접근 제어자는 영향을 주지 않음
* Overriding 관련 개념 : 상속 상위 클래스의 메소드를 하위 클래스에서 재정의
	
# 22. Call by Reference, Call by Value

* Call by Reference - 매개 변수의 원래 주소에 값을 저장하는 방식. 클래스 객체를 인수로 전달한 경우
* Call by Value - 인수로 기본 데이터형을 사용. 주어진 값을 복사하여 처리하는 방식. 메서드 내의 처리 결과는 메서드 밖의 변수에 영향을 미치지 않는다.

# 23. Static

* 클래스가 로딩될 때, 메모리 공간을 할당하는데 처음 설정된 메모리 공간이 변하지 않음을 의미
* 객체를 아무리 많이 만들어도 해당 변수는 하나만 존재(객체와 무관한 키워드)
	
# 24. Index (Database)

인덱스는 데이터베이스 분야에 있어서 테이블에 대한 동작의 속도를 높여주는 자료 구조를 일컫는다.
인덱스는 테이블 내의 1개의 컬럼, 혹은 여러 개의 컬럼을 이용하여 생성될 수 있다.
고속의 검색 동작뿐만 아니라 레코드 접근과 관련 효율적인 순서 매김 동작에 대한 기초를 제공한다.
인덱스를 저장하는 데 필요한 디스크 공간은 보통 테이블을 저장하는 데 필요한 디스크 공간보다 작다.
데이터베이스에서 테이블과 클러스터에 연관되어 독립적인 저장 공간을 보유하고 있는 객체(object)이다.
사용자는 데이터베이스에 저장된 자료를 더욱 빠르게 조회하기 위하여 인덱스를 생성하고 사용한다.
* DB에서 자료를 검색하는 두 가지 방법
  * FTS(Full Table Scan) : 테이블을 처음 부터 끝까지 검색하는 방법
  * Index Scan : 인덱스를 검색하여 해당 자료의 테이블을 액세스 하는 방법.

# 25. 자료구조

	코딩인터뷰 완전 정복

# 26. 알고리즘

	코딩인터뷰 완전 정복
