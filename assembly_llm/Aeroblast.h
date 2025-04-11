#include <string>

class Aeroblast {
public:
	Aeroblast(const std::string& apiKey);
	std::string classify(const std::string& functionCode);

private:
	std::string apiKey;
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
	std::string generateCostarPrompt(const std::string& functionCode);
};

