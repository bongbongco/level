정리 중...

1. HTTP/HTTP 2.0  
----------------

1) HTTP  
-------

 Huyper Text Transfer Protocol의 약자로 WWW(World Wide Web)에서 하이퍼텍스트(hypertext) 문자를 교환하기 위하여 사용되는 통신규약.

		1-1) Status code : HTTP 통신 중 요청의 상태 정보 제공
			(1) 1xx - Informational - 정보교환
			(2) 2xx - Success - 성공
				200 - OK	- 요청이 성공적으로 전송됨
			(3) 3xx - Redirection - 방향 지정
				301 - Moved Permanently - 요청 페이지의 영구적인 위치 변화
				302 - Found	- 요청 페이지이 일시적인 위치 변화
			(4) 4xx - Client Error - 클라이언트 오류
				404 - Not Found - 요청받은 자원을 서버에서 찾을 수 없을때 나타나는 상태 
				405 - Method Not Allowed - 서버에서 사용자가 요청한 주소의 메소드를 지원하지 않을때 나타남
			(5) 5xx - server Error - 서버 오류

		1-2) Request Method : 
			(1) OPTIONS: 요청한 URL에 어떠한 메소드 요청이 가능한지 묻는다.
			(1) GET: 다른 작업없이 데이터의 검색에 이용.
			(2) HEAD: 데이터의 검색에 이용하나 GET과는 다르게 응답 HEADER만 받는다.
			(3) POST: URL에 새로운 데이터를 보낼때 사용.
			(4) PUT: URL에 저장될 정보를 보낸다.
			(5) DELETE: URL의 리소스를 삭제한다.
			(6) TRACE: 보낸 메세지를 다시 돌려받는다.
			(7) CONNECT: 프록시에서 사용되는 예약 메소드.
		
	2) HTTP 2.0
 Latency(지연 시간)를 줄여 웹의 속도를 개선하기 위해 등장. 효율적인 페이지 로딩을 위해 URL의 이미지, 스크립트등의 자원을 압축해 페이지 렌더링을 위한 요청횟수를 감소시켰다. 뿐만 아니라 server가 push가 가능해 웹페이지의 렌더링이 필요하단 사실을 알게되면 추가 요청없이 서버가 리소스를 제공한다. 그 외에도 성능 개선을 위한 요청 다중화, 헤더 압축, HOL Blocking해결을 위한 요청 우선순위 결정등이 있다.
 
	2-1) 특징
		(1) HTTP Header 데이터 압축
		(2) Server Push(서버에서 부터 시작되는 전송)
		(3) HTTP 1에서 존재하던 head-of-line blocking 문제 개선
		(4) 싱글 TCP connection내에서 병렬 페이지 로딩 구현
		2.0은 기존 버전인 1.1과의 높은 호환성(method, status codes 등)은 보장하고 클라이언트 서버 간 전송 및 프레임의 개선에 초점을 맞췄다.
		※ head-of-line blocking: 동일한 송신 포트 자원에 대한 처리량 경쟁으로 인해 처리량 지연 및 프레임 손실 발생 유발. 작업대기 중인 2개의 패킷이 존재할 경우 첫번째 패킷이 대기중이면 그 뒤 패킷들은 무조건 대기할때 발생
 
	2-2) HTTP 2.0과 SPDY
		(1) SPDY : Google이 ‘speedy’라는 단어를 기반으로 제안한 새로운 프로토콜이다. HTTP의 단점들을 보완하여, 인터넷 환경을 보다 효율적으로 이용하기 위한 프로토콜이다. HTTP/2.0에서는 스펙에 SPDY를 반영할 예정이다.
		(2) 특징
			- TLS 위에서 동작한다. https에서만 적용가능
			- HTTP 헤더를 압축한다. 요청마다 반복되는 내용을 압축해 성능 향상 효과가 나타남
			- 바이너리로 프레임을 구성한다. 파싱 속도가 향상되고 오류확률은 낮아진다.
			- 다중 연결을 지원한다.	다수의 요청, 응답 을 동시에 처리 할 수 있어 속도 향상
			- 인터리빙을 허용한다. 우선순위가 높은 데이터가 더 빨리 전송 될 수있다.
			- 서버 푸시가 가능하다.
		
	
	3) 결론
 HTTP 1.1 이 사용하는 전송방식(RFC7230)에는 몇가지 문제점이 존재했다. HTTP/1.0은 TCP connection에서 한번에 하나의 요청 만이 가능했고 HTTP/1.1에서는 그보다 발전하여 request pipelining을 사용했지만 여전히 HOL Blocking 문제가 존재했다. HTTP/2.0은 오랫동안 변화하지 않았던 HTTP를 현 웹 환경에 맞게 발전시켜 속도의 향상을 도모 한다는데 크 의의가 있다.

 
2. HTTPS
========
HTTP에 인증과 안전성을 더해서 안전한 통신을 지원하는 통신 규약(HTTP는 도청, 위장, 변조의 위험이 존재).
새로운 프로토콜이 아니라, HTTP 프로토콜의 소켓을 SSL이나 TLS로 대체하여 TCP로 직접 통신하지 않고 SSL과 통신하게 하여 암호화와 인증서를 이용할 수 있게 한다.
※ SSL : HTTP와 독립된 프로토콜로 어플리케이션 계층에서 동작하는 다른 프로토콜에도 적용이 가능하다.
하이브리드 암호 시스템?
HTTPS는 공통키 암호와 공개키 암호의 양쪽 성질을 가진 하이브리드 암호 시스템입니다.
두가지 방식을 조합해서 장점을 살립니다.
키를 교환하는 곳에서는 공개키 암호를 사용하고 그 후의 통신에서 메시지를 교환하는 곳에서는 공통키 암호를 사용합니다.

공통키 암호

상호간에 키를 교환하는 암호화 방식을 공개키 암호화 방식이라고 합니다.
SSL에서는 공개키 암호화 방식을 채용하고 있습니다.
암호화, 복호화에 하나의 키를 같이 사용하는 방식입니다.

하지만 키를 누군가 손에 넣으면 누구라도 암호를 해독할 수 있는 문제가 있습니다.

공개키 암호

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


3. TCP / UDP
============
	1) TCP
		(1) 정의 : 연결형 서비스를 위해 호스트 간 신뢰성 있는 데이터 전달과 흐름제어 및 혼잡제어 등을 제공하는 전송계층 프로토콜로 인터넷 환경에서 기본으로 사용된다. 
		
		(2) 특징
			- 가상 회선 연결 방식, 연결형 서비스를 제공
			- 높은 신뢰성(Sequence Number, Ack Number를 통한 신뢰성 보장)
			- 연결의 설정(3-way handshaking)과 해제(4-way handshaking)
			- 데이터 흐름 제어(수신자 버퍼 오버플로우 방지) 및 혼잡 제어(네트워크 내 패킷 수가 과도하게 증가하는 현상 방지)
			- 전이중(Full-Duplex), 점대점(Point to Point) 서비스
		
		(3) 소켓 통신 과정
			- 서버 : 소켓을 생성, 주소 할당, 연결 요청 기다림, 요청에 대한 응답
			- 클라이언트 : 소켓을 생성, 주소 할당, 연결 요청		
			
	2) UDP
		(1) 정의 : 비연결형 서비스를 지원하는 전송계층 프로토콜로 정보를 보낸다는 신호나 받는다는 신호 절차를 거치지 않고, 일방적으로 데이터를 전달. 

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

			UDP는 TCP와 달리 데이터의 수신에 대한 책임을 지지 않는다. 이는 송신자는 정보를 보냈지만, 정보가 수신자에게 제때에 도착했는지 또는 정보 내용이 서로 뒤바뀌었는지에 관해서 송신자는 상관할 필요가 없다. TCP보다 안정성 면에서는 떨어지지만, 속도는 훨씬 빠르다.

	
4. 쿠키/세션
===========
	1) 쿠키/세션이 필요한 이유
		- HTTP 프로토콜은 연결 지향적인 통신이 아니므로 페이지 이동 시 마다 새로운 접속이 이루어지며 이전 페이지와 현재 페이지 간의 관계가 지속되지 않는다. 이러한 문제를 해결하기 위해서 쿠키와 세션을 사용한다.
	2) 쿠키
		- Client PC에 저장되어 다른 사용자에 의한 임의 변경 위험이 있다.
		- 생성 이후 서버로 전송되는 요청에는 쿠키 정보가 같이 포함되어 전송
		- 이름, 값, 유효기간, 도메인, 경로 등으로 구성
	3) 세션
		- Session에 관련된 데이터는 Server에 저장된다.
		- 웹 브라우저의 캐시에 저장되어 브라우저가 닫히거나 서버에서 삭제 시 사라진다.
		- Cookie에 비해 보안성이 좋다.
		- 저장 데이터에 제한 없음
		
		
5. 소켓서버/웹서버
=================
	1) 소켓서버
	http://www.gpgstudy.com/gpgiki/%EC%86%8C%EC%BC%93_%EA%B0%95%EC%A2%8C
	2) 웹서버
	http://sungbine.github.io/tech/post/2015/02/15/tomcat%EA%B3%BC%20apache%EC%9D%98%20%EC%97%B0%EB%8F%99.html
	https://okky.kr/article/243427
	https://github.com/lesstif/web-service-hardening/blob/master/web-server.md
	http://round1tko.tistory.com/64
	
6. IOCP
=======
 IOCP는 Input/Output Completion Port의 약자로 입력과 출력의 완료를 담당할 포트를 지정해서 처리하겠다는 의미이다. 입력과 출력의 완료시점에서의 통지는 overlapped(중첩 입출력)에서 처리가 되므로, 이 기술은 윈도의 중첩 입출력 기술을 확장시킨 것으로 볼 수 있다.
포트는 작업 혹은 서비스를 전담하기 위해서 만들어지는 객체다. 소켓의 포트가 특정 서비스로 데이터 입출력을 전달하기 위한 객체임을 상기하면 이해가 쉬울 것이다. 이러한 포트의 특징을 이해하면, 입출력 완료 시점에서 이에 대한 통지를 전담할 포트를 만들어서 데이터를 처리하는 방식도 충분히 생각해 볼 수 있을 것이다.
 https://www.joinc.co.kr/w/Site/win_network_prog/doc/iocp
 http://ozt88.tistory.com/23
 
7. 하둡
=======
 대량의 자료를 처리할 수 있는 큰 컴퓨터 클러스터에서 동작하는 분산 응용 프로그램을 지원하는 프리웨어 자바 소프트웨어 프레임워크이다.
 http://www.itworld.co.kr/print/73626
 
8. jquery / bootstrap / ajax
=============================
	0) javascript : 자바스크립트는 ECMAScript 표준 명세를 따라 구현된 객체 기반 스크립트 프로그래밍 언어이다. HTML 태그 또는 엘리먼트라고 불리는 DOM(Document Object Model)과 BOM(Browser Object Model)을 조작하거나, SPA(Single Page Application)에서 서버와 Ajax 통신을 하는 용도로 주로 사용된다.
	https://github.com/nhnent/fe.javascript/wiki/%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0
	
	1) jquery : 자바스크립트의 생산성을 향상시켜주는 자바스크립트 라이브러리
	
	2) bootstrap : 트위터에서 시작된 HTML5 기반의 오픈 소스 웹 디자인 프레임워크
		
	3) ajax : Web에서 화면을 갱신하지 않고 Server로 부터 Data를 가져오는 방법
		(1) 동작원리 : Ajax의 동작원리는 Browser에서 서버로 보낼 Data를 Ajax Engine을 통해 Server로 전송합니다. 이 때 Ajax Engine에서는 JavaScript를 통해 DOM을 사용하여 XMLHttpRequest(XHR) 객체로 Data를 전달합니다. 이 XHR을 이용해서 Server에서 비동기 방식으로 자료를 조회해 올 수 있습니다. Server에서 Data를 전달 할 때 화면전체의 HTML을 전달하지 않고 Text 또는 Xml형식으로 Browser에 전달합니다.
	
		http://www.nextree.co.kr/p4771/
	
	
9. 웹앱
=======
 브라우저를 이용한 HTML, CSS, 자바스크립트를 사용해 만들어진 어플리케이션으로 인터넷 서비스도 이에 포함된다.
 
 http://d2.naver.com/helloworld/179084
 
 
10. aws (ec2 / elastic search / dynamodb/lambda)
================================================
	1) EC2 : EC2(Elastic Compute Cloud)는 AWS 클라우드에서 확장식 컴퓨팅을 제공한다. 
	http://docs.aws.amazon.com/ko_kr/AWSEC2/latest/UserGuide/concepts.html
	
	2) Elastic Search : 아파치 루씬을 기반으로 개발된 오픈소스 분산검색엔진
	http://d2.naver.com/helloworld/273788
	http://opennote46.tistory.com/143
	http://elasticsearch.tistory.com/entry/elasticsearch%EB%9E%80
	
	
		※ 루씬 : http://killsia.tistory.com/443
		
	3) DynamoDB
	https://yangbongsoo.gitbooks.io/study/content/dynamodb2.html
	https://www.slideshare.net/awskr/dynamodb-42890664+&cd=5&hl=ko&ct=clnk&gl=kr
	http://docs.aws.amazon.com/ko_kr/amazondynamodb/latest/developerguide/Introduction.html
	
	4) Lambda
	http://gun0912.tistory.com/59
	http://gun0912.tistory.com/60
	https://aws.amazon.com/ko/blogs/korea/category/aws-lambda/
	https://www.slideshare.net/awskorea/aws-lambda-100-sangpil-kim

11. python / flask / sphinx
===========================
	1) Python
	https://wikidocs.net/6
	
	2) Flask
	https://spoqa.github.io/2012/01/16/wsgi-and-flask.html
	https://code.tutsplus.com/ko/tutorials/an-introduction-to-pythons-flask-framework--net-28822
	
	3) Sphinx
	http://sacstory.tistory.com/entry/Debian-%EA%B2%80%EC%83%89-%EC%97%94%EC%A7%84-Sphinx-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0
	http://crystalcube.co.kr/165
	http://wiki.pchero21.com/wiki/Sphinx
	
12. nginx / apache
==================
	1) Nginx
	https://opentutorials.org/module/384/3462
	http://d2.naver.com/helloworld/192785
	https://openwiki.kr/tech/nginx
	http://www.haruair.com/blog/1900
	
	2) Apache
	https://wiki.archlinux.org/index.php/Apache_HTTP_Server_(%ED%95%9C%EA%B5%AD%EC%96%B4)
	http://cs.sch.ac.kr/lecture/Embedd/06-CompSys-8-Apache.pdf

13. mysql / mariadb
===================
	1) Mysql
	https://wiki.gentoo.org/wiki/MySQL/Startup_Guide/ko
	Mysql 퍼포먼스 최적화
	
	2) MariaDB
	https://mariadb.com/kb/ko/mariadb/

14. rabbitmq / redis
====================
	1) RabbitMQ
	http://blog.saltfactory.net/install-rabbitmq/
	http://bcho.tistory.com/786
	http://abh0518.net/tok/?p=384
	https://github.com/gjchoi/gjchoi.github.io/blob/master/_posts/2016-02-27-rabbit-mq-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0.md
	http://hamait.tistory.com/401
	http://blog.hkwon.me/rabbitmq-php-node-jsreul-hwalyonghae-gcm-push-ceorihagi/
	
	2) Redis
	http://tech.kakao.com/2016/03/11/redis-scan/
	http://bcho.tistory.com/654
	http://kerocat.tistory.com/1
	http://d2.naver.com/helloworld/614607
	
	
15. json query
==============
	1) Json Query
	
	
16. monitoring / alert
======================
	1) Monitoring / Alert
	http://blurblah.net/1474
	http://mysqldbadmtech.blogspot.kr/2016/12/pmm-170-mysql-alert.html
	http://tech.whatap.io/2017/04/21/twitter_monitoring_and_alert-system/
	https://geunhokhim.wordpress.com/2017/01/02/grafana-influxdb-telegraf-monitoring-server-alerting-automation/
	http://tech.kakao.com/2016/08/25/kemi/
	https://engineering.linecorp.com/ko/blog/detail/147
	https://blog.outsider.ne.kr/1254
	

17. 최근 관심 분야
=================
함수형 프로그래밍에 관심이 있다. 함수형 프로그래밍이 객체지향형 프로그래밍을 대체할 것이라는 말을 들어서 진짜 그게 가능할까하고 훑어봤는데, 그 동안 생각하지 못했던 요소들이 많아서 사고력을 키우는 차원에서 관심을 가지고 학습하려고 합니다.

예를 들어 러스트라는 함수형 프로그래밍언어는 기본 변수 타입이 상수이고 변수를 사용하기 위해서는 별도로 지정해야한다고 해서 설계한 의도가 무엇일까 생각했던 것이 생각난다.

아마도 명확한 코드를 지향해서 그런 것이라 판단했다.


18. 보고 있는 책(공부하고 있는 분야)
=================================

***
19. 객체지향
===========
	데이터를 객체로 취급하여 객체 간의 상호작용을 통해 프로그램이 동작하게 하는 설계 기법
	코드 재사용성이 높다.
	코드의 변경이 쉽다.
	코드 분석이 쉽다.
	객체지향 원칙을 사용하여(캡슐화, 상속, 다형성) 개발속도가 빨라진다.
20. Object
==========
	객체는 객체지향프로그래밍에서 데이터와 그 데이터에 관련되는 동작, 모두가 포함되는 개념
21. Overloading과 Overriding
============================
	Overloading 같은 이름의 메소드를 여러 개 정의	정의된 메소드의 매개변수는 타입이나 개수가 다름 return type과 접근 제어자는 영향을 주지 않음

	Overriding 관련 개념 : 상속 상위 클래스의 메소드를 하위 클래스에서 재정의
	
22. Call by Reference, Call by Value
====================================
	Call by Reference - 매개 변수의 원래 주소에 값을 저장하는 방식. 클래스 객체를 인수로 전달한 경우
	Call by Value - 인수로 기본 데이터형을 사용. 주어진 값을 복사하여 처리하는 방식. 메서드 내의 처리 결과는 메서드 밖의 변수에 영향을 미치지 않는다.

23. Static
==========
	클래스가 로딩될 때, 메모리 공간을 할당하는데 처음 설정된 메모리 공간이 변하지 않음을 의미
	객체를 아무리 많이 만들어도 해당 변수는 하나만 존재(객체와 무관한 키워드)
	
24. Index (Database)
====================
	인덱스는 데이터베이스 분야에 있어서 테이블에 대한 동작의 속도를 높여주는 자료 구조를 일컫는다.
	인덱스는 테이블 내의 1개의 컬럼, 혹은 여러 개의 컬럼을 이용하여 생성될 수 있다.
	고속의 검색 동작뿐만 아니라 레코드 접근과 관련 효율적인 순서 매김 동작에 대한 기초를 제공한다.
	인덱스를 저장하는 데 필요한 디스크 공간은 보통 테이블을 저장하는 데 필요한 디스크 공간보다 작다.
	데이터베이스에서 테이블과 클러스터에 연관되어 독립적인 저장 공간을 보유하고 있는 객체(object)이다.
	사용자는 데이터베이스에 저장된 자료를 더욱 빠르게 조회하기 위하여 인덱스를 생성하고 사용한다.
	DB에서 자료를 검색하는 두 가지 방법
	FTS(Full Table Scan) : 테이블을 처음 부터 끝까지 검색하는 방법
	Index Scan : 인덱스를 검색하여 해당 자료의 테이블을 액세스 하는 방법.

25. 자료구조
===========
	코딩인터뷰 완전 정복
26. 알고리즘
============
	코딩인터뷰 완전 정복
