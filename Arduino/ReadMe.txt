1. 두 대의 아두이노, SERVO모터, IR센서, Xbee가 필요함
2. 첫 번째 아두이노는 USB로 PC에 직접 연결함. IR 센서가 부착됨
	PIR_Part 소스가 업로드되어야 함
3. 두 번째 아두이노는 SERVO 모터가 장착되고 외부 전원을 통해 독자적으로 설치됨.
	두 번쨰 아두이노에는 Xbee 쉴드가 있어야 함
	SERVO_Part 소스가 업로드되어야 함
4. PC에는 Xbee 통신 모듈이 USB케이블을 통해 연결되어 있어야 함
5. Client-Processing을 PC에서 실행하면 투석기를 원격에서 제어할 수 있음