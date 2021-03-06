if __name__ == '__main__':
	N, K = list(map(int,input().split()))
	
	arr = [1]*(N+1) # 1로 초기화된 배열(k = 1이면 합을 구할 수 있는 방법 단 하나(자기 자신)), 크기는 N+1(0도 포함시켜야 하기 때문)
	for _ in range(1,K): # k가 1일 때는 이미 1로 초기화 하면서 구했기 때문에 2일때부터 구할 것
		for i in range(1,N+1):
			arr[i] += arr[i-1] # 본인 위치의 배열 값 + 이전 배열 값으로 갱신
			arr[i] %= 1000000000 # 1000000000으로 나눈 나머지를 출력해야하므로 1000000000로 나눈 값 저장
		
	print(arr[N])
