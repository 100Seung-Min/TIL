void clent()
{
	system("cls");
	SOCKET s;
	WSADATA wsaData;
	SOCKADDR_IN sin;

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) {
		printf("WSAStartup 실패, 에러코드 : %d\n", WSAGetLastError());
		return 0;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) {
		printf("소켓 생성 실패, 에러코드 : %d\n", WSAGetLastError());
		WSACleanup(); return 0;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (connect(s, (SOCKADDR*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러코드 : %d\n", WSAGetLastError());
		closesocket(s); WSACleanup(); return 0;
	}

	printf("승민님과 연결되었습니다.\n");

	char buffer[1024];
	while (1) {
		printf("\n");
		printf("시훈 : ");
		scanf("%s", buffer);
		send(s, buffer, strlen(buffer) + 1, 0);
		recv(s, buffer, 1024, 0);

		printf("\n승민 : %s\n", buffer);
	}
	if (closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러 코드 : %d\n", WSAGetLastError());
		WSACleanup(); return 0;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup 실패, 에러코드 : %d\n", WSAGetLastError());
		return 0;
	}

	return 0;
}