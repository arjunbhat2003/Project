#include <iostream>
#include <string>
using namespace std;
int CheckPattern(const string& text, const string& pattern,
                 const int& find_first = 0) {  // function takes text and
                                               // pattern and outputs how many
                                               // instances found
  string temp_text = text;
  string temp_pattern = pattern;
  int num_p = 0;
  int index = 0;
  int counter = 0;                       // intits variables
  while (int(temp_text.length()) > 0) {  // until text is an empty string
    if (index == int(temp_pattern.size())) {  // if pattern is found
      temp_text.erase(0, 1);  // removes single character from beginning
      num_p++;
      index = 0;
      if (find_first == 1) return counter;  // used for FindFirstOf function
    }
    if (temp_pattern[index] == '%') {
      index++;
    } else if (temp_pattern[index] == '#' && isdigit(temp_text[index])) {
      index++;
    } else if (temp_pattern[index] == temp_text[index]) {
      index++;
    } else {
      temp_text.erase(0, 1);  // removes single character from beginning
      index = 0;
      counter++;
    }
  }
  if (find_first == 1)
    return -1;  // If pattern not found for FindFirstOf function
  return num_p;
}
void To_Lower(
    string& text,
    string& pattern) {  // converts text and pattern to lowercase strings
  transform(text.begin(), text.end(), text.begin(), ::tolower);
  transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
}
bool ImprovedContains(const string& text, const string& pattern,
                      const bool* pointer) {
  string temp_text = text;
  string temp_pattern = pattern;
  if (*pointer == true) To_Lower(temp_text, temp_pattern);
  int num_p = CheckPattern(
      temp_text, temp_pattern);  // gets num of instances of pattern in text
  if (num_p > 0) {
    return true;
  } else {
    return false;
  }
}
int ImprovedMatches(const string& text, const string& pattern,
                    const bool* pointer) {
  string temp_text = text;
  string temp_pattern = pattern;
  if (*pointer == true) To_Lower(temp_text, temp_pattern);
  int num_p = CheckPattern(
      temp_text, temp_pattern);  // gets num of instances of pattern in text
  return num_p;
}
int ImprovedFindFirstOf(const string& text, const string& pattern,
                        const bool* pointer) {
  string temp_text = text;
  string temp_pattern = pattern;
  if (*pointer == true) To_Lower(temp_text, temp_pattern);
  return CheckPattern(temp_text, temp_pattern,
                      1);  // returns index of first instance of pattern in text
}
void ImprovedReplace(string& text, const string& pattern,
                     const string& new_content, const bool* pointer) {
  int index = ImprovedFindFirstOf(
      text, pattern,
      pointer);       // gets index of first instance of pattern in text
  if (index != -1) {  // if pattern is found
    text.replace(index, int(pattern.size()), new_content);
  }
}
int ImprovedNumberOfDifferences(const string& str_1, const string& str_2,
                                const bool& case_sens) {
  string new_str_1 = str_1;
  string new_str_2 = str_2;
  if (case_sens == true) To_Lower(new_str_1, new_str_2);
  int counter = 0;
  for (int i = 0; i < int(str_1.size()); i++) {
    if (new_str_1[i] != new_str_2[i]) {
      counter++;
    }
  }
  return counter;
}