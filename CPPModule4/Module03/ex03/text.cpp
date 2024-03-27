// -Wshadow 옵션은 지역변수가 덮어씌워지거나 매개변수가 덮어씌워지면 경고를 해주는 옵션이다.
// clang++ -Wshadow test.cpp 로 컴파일을 할 경우 경고를 해준다.
// 그리고 여기서 clang++ -Wshadow -Wno-shadow test.cpp 로 컴파일을 할 경우 두번째 사진처럼 경고가 없어진다.
// -Wno-shadow는 -Wshadow의 경고가 안나오게 해주는 옵션이다.