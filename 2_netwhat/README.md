# Netwhat

## :mag_right:Evaluated
+ score : 100

## **IP4**

- 8bit씩 4개의 10진수 값 (size: 8 x 4 =32bit)
- 0.0.0.0 ~ 255.255.255.255

## **IP6**

- 16bit씩 8개의 16진수 값 (size: 16 x 8 = 128bit)
- C0FA : 998F : 7A8D : 00D2 : DE05 : 11C4 : 777C : 4B9F (한 자리당 4bit)
- 16진수로 C는 2진수로 변환했을 때 1100 이니까 4bit

## **IP주소 CLASS**

- consist of A,B,C,D,E class
- A class = First class? which has more host addresses available by default
- C class = default class available?

## **Loopback address**

- 127.0.0.1 test ip stack on your local host
- think of ft_server

## **Public/Private IP address**

- **공인 IP주소** : 공인된 할당기관에서 할당해준 IP주소, 인터넷 상에서 사용할 수 있음
- **사설 IP주소** : 내부 네트워크에서만 사용하는 IP주소, 인터넷 상에서 사용할 수 없음 (폐쇄형)
    - Class A : ***10***.0.0.0 ~ 10.255.255.255
    - Class B : ***172.16***.0.0 ~ 172.31.255.255
    - Class C : ***192.168***.0.0 ~ 192.168.255.255

## SubnetMask

- CIDR(classless inter-domain routing) a.k.a 사이더
- IP 주소에서 192.168.0.1/24 혹은 192.168.0.1 서브넷 마스크:255.255.255.0 과 같은 것을 본 적이 있을 것이다. 여기서 /24 와 /255.255.255.0 은 같은 것을 나타내는데, 255.255.255.0 을 2진수로 쓰면 1111 1111.1111 1111.1111 1111.0000 0000이다. 여기서 앞에서부터 연속된 1의 개수만 나타낸 것이 /24 이다.
- 주소가 고갈되니 서브넷마스크, 사이더를 사용함으로써 더 세부적으로 나눠서 주소 양을 늘리려고 한 것.

## Network/Broadcast address

- **네트워크 주소** : 하나의 네트워크를 통칭하기 위함
    - 해당 네트워크의 첫번째 IP주소
    - 계산방법 : IP주소와 서브넷마스크의 AND연산
    - Adresse Reseau
- **브로드캐스트 주소** : 네트워크에 있는 클라이언트 모두에게 데이터를 보내기 위함
    - 해당 네트워크의 마지막 IP주소
    - 계산방법 : 서브넷 마스크의 '0'인 부분을 모두 1로 바꿈
    - Adresse Broadcast

## Host address

- Nombre de Machines 호스트 주소 개수
- Premiere machine ~ Derniere machine 유효한 호스트주소 범위
- If the IP address 123.48.189.194/21 is assigned to an Ethernet port of a router, what host address could communicate with it? 범위내의 주소 찍으면됨

## **OSI Model**

- OSI는 Open System Interconnection의 약자
- 컴퓨터 네트워크 프로토콜 디자인과 통신을 7계층으로 나누어 설명한 것

[Untitled](https://www.notion.so/d9e57cc3898c48019ab6c960c3d0d62a)

- 참고 : [OSI모형](https://ko.wikipedia.org/wiki/OSI_%EB%AA%A8%ED%98%95)
- APSTNDP

## **Transport Layer**

- 전송계층은 양 단의 사용자들이 신뢰성있는 데이터를 주고 받을 수 있도록 해줌
- **TCP** *(Transmission Control Protocol)*
    - 전송 제어 프로토콜, IP와 함께 TCP/IP라고도 불림
    - 일련의 옥텟을 안정적으로, 순서대로, 에러없이 교환할 수 있도록 해줌
    - 사용 : 웹브라우저에서 www 연결, 이메일전송, 파일전송 등
- **UDP** *(User Datagram Protocol)*
    - 사용자 데이터그램 프로토콜
    - 전송방식이 단순하여 순서가 바뀌거나 중복되거나 통보없이 누락되기도 함
    - 사용 : DNS, IPTV, VoIP, 온라인게임 등

- tcp: SMTP(전자메일), FTP(파일주고받기), HTTP(웹사이트)
- udp: DHCP(동적 호스트 설정 프로토콜)

## **Network Layer**

- 네트워크 계층은 라우팅, 패킷 포워딩을 담당함
- **ICMP** *(Internet Control Message Protocol)*
    - 인터넷 제어 메세지 프로토콜
    - 네트워크 컴퓨터의 OS에서 오류 메시지를 전송받는 데 주로 쓰임
    - 'Echo request', 'Echo reply', 'Destination Unreachable', 'Time Exceeded' 등
    - 사용 : 핑(Ping), 트레이스라우트(traceroute)
- 참고 : [ICMP](https://ko.wikipedia.org/wiki/%EC%9D%B8%ED%84%B0%EB%84%B7_%EC%A0%9C%EC%96%B4_%EB%A9%94%EC%8B%9C%EC%A7%80_%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C)

## **Calculator**

- [http://jodies.de/ipcalc?host=133.159.10.17&mask1=255.192.0.0&mask2=](http://jodies.de/ipcalc?host=133.159.10.17&mask1=255.192.0.0&mask2=)
