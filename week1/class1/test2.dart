import 'dart:io';

void main() {
  String? input = stdin.readLineSync();
  bool foundVowel = false;
  List<String> inputCharacters = input!.split('');
  int length = input.length;
  for (int i = 0; i < length; i++) {
    if (inputCharacters[i] == 'a' || inputCharacters[i] == 'A') {
      foundVowel = true;
      break;
    } else if (inputCharacters[i] == 'e' || inputCharacters[i] == 'E') {
      foundVowel = true;
      break;
    } else if (inputCharacters[i] == 'i' || inputCharacters[i] == 'I') {
      foundVowel = true;
      break;
    } else if (inputCharacters[i] == 'o' || inputCharacters[i] == 'O') {
      foundVowel = true;
      break;
    } else if (inputCharacters[i] == 'u' || inputCharacters[i] == 'U') {
      foundVowel = true;
      break;
    }
  }

  if (foundVowel) {
    print("The string contains a vowel.");
  } else {
    print("The string does not contain any vowel.");
  }
}
