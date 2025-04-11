#include "Aeroblast.h"
#include <iostream>
#include <string>
//#include <curl.h>
//#include <json.h>

Aeroblast::Aeroblast(const std::string& in_apiKey)
{
	apiKey = in_apiKey;
}

size_t Aeroblast::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string Aeroblast::generateCostarPrompt(const std::string& functionCode)
{
	std::string combiner_costar_prompt_template_CodeInjection =
		"# CONTEXT #\n"
		"As a Malware Analyse and Malware Reverse engineer support assistant, your role involves addressing cybersecurity queries specifically related to Malware analysis and Malware reverse engineering domain\n"
		"\n"
		"#########\n"
		"\n"
		"# OBJECTIVE #\n"
		"Examine a given malware code and determine whether a Process Code Injection occurs in it.\n"
		"\n"
		"#########\n"
		"\n"
		"# STYLE #\n"
		"Adopt a professional and technical writing style appropriate for cybersecurity support, using Markdown formatting to enhance the clarity and structure of the response.\n"
		"\n"
		"#########\n"
		"\n"
		"# TONE #\n"
		"Maintain a formal and informative tone, focusing on delivering clear and authoritative information.\n"
		"\n"
		"#########\n"
		"\n"
		"# AUDIENCE #\n"
		"The response is intended for Malware analysts, Malware reverse engineers, and SOC analysts with an understanding of technical and cybersecurity concepts.\n"
		"\n"
		"#########\n"
		"\n"
		"# RESPONSE #\n"
		"The response should be text based, without showing code, and no longer than 3 sentences.\n"
		"\n"
		"# EXAMPLES SECTION #\n";

	return combiner_costar_prompt_template_CodeInjection + functionCode;
}

std::string Aeroblast::classify(const std::string& functionCode)
{
	return "";
}
