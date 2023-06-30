#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong input!\nInput argv must be 4\n";
        return (1);
    }
    std::string filename = argv[1];
    std::cout << filename << "\n";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return (1);
    }

    std::string fileBuffer;
    std::string lineBuffer;

    while(std::getline(file, lineBuffer)){
        fileBuffer += lineBuffer + "\n";
    }
    file.close();

    std::string s1 = argv[2];
    std::string s2 = argv[3];

    unsigned int linepos = 0;
    unsigned int pos = 0;
    
    unsigned int fileBufferLen = fileBuffer.size();
    unsigned int s1_Len = s1.size();
    unsigned int s2_Len = s2.size();

    std::string result;

    std::cout << "파일 내용:" << std::endl;
    std::cout << fileBuffer << std::endl;

    while (1)
    {
        pos = fileBuffer.find(s1, linepos);
        if (fileBufferLen < pos)
        {
            result += fileBuffer.substr(linepos);
            break;
        }
        result += fileBuffer.substr(linepos, pos - linepos);
        result += s2;
        linepos = pos + s1_Len;
    }

    std::cout << "최종결과\n";
    std::cout << result << "\n";

    std::string newfile = filename.append(".replace");
    std::cout << "저장 파일 : " << newfile << "\n";

    std::ofstream out(newfile.c_str(), std::ios::out);
	if (!out.good())
	{
		std::cout << "Error while opening\n";
		return (1);
	}
	out << result;
	out.close();
    return (0);
}