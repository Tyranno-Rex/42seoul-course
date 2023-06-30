// #include <iostream>
// #include <fstream>
// #include <string>

// // 특정 문자열을 다른 문자열로 교체하는 함수
// void replace(std::string& buffer, const std::string& searchStr, const std::string& replaceStr) {
//     size_t pos = 0;
//     while ((pos = buffer.find(searchStr, pos)) != std::string::npos) {
//         buffer.replace(pos, searchStr.length(), replaceStr);
//         pos += replaceStr.length();
//     }
// }

// int main() {
//     std::string filename = "test";
//     std::ifstream file(filename);

//     if (!file.is_open()) {
//         std::cerr << "파일을 열 수 없습니다." << std::endl;
//         return 1;
//     }

//     std::string buffer;
//     std::string line;

//     // 파일 내용을 버퍼에 저장
//     while (std::getline(file, line)) {
//         buffer += line + "\n";
//     }

//     file.close();

//     // 교체할 문자열과 대체할 문자열 설정
//     std::string searchStr = "that"; // 교체할 문자열을 여기에 입력하세요
//     std::string replaceStr = "11111"; // 대체할 문자열을 여기에 입력하세요

//     // 특정 문자열을 다른 문자열로 교체
//     replace(buffer, searchStr, replaceStr);

//     // 결과 출력
//     std::cout << "교체 후 파일 내용:" << std::endl;
//     std::cout << buffer << std::endl;

//     return 0;
// }
