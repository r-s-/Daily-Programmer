//DailyProgrammer Challenge
//number 88
//r-s

/*
You take a message that you want to encrypt, for instance "THECAKEISALIE"
(lets assume that all characters are upper-case and there are no spaces in
the messages, for the sake of simplicity), and a key you want to encrypt it
with, for instance "GLADOS". You then write the message with the key repeated
over it, like this:
GLADOSGLADOSG
THECAKEISALIE
The key is repeated as often as is needed to cover the entire message.
Now, one by one, each letter of the key is "added" to the letter of the
clear-text to produce the cipher-text. That is, if A = 0, B = 1, C = 2, etc,
then E + G = K (because E = 4 and G = 6, and 4 + 6 = 10, and K = 10). If the
sum is larger than 25 (i.e. larger than Z), it starts from the beginning, so
S + K = C (i.e. 18 + 10 = 28, and 28 - 26 is equal to 2, which is C).
*/
#include <iostream>
#include <string>
#include <vector>

std::string encrypt (std::string msg, std::string key)
{
  unsigned int x = 0;
  std::string t = key;
  key.erase(key.begin(), key.end());

  for (std::string::size_type i = 0; i<msg.length(); i++)
  {
    key.push_back(t[x++]);
    if (x>t.length()-1)
    {
      x = 0;
    }
  }

  for (std::string::size_type i = 0; i<msg.length(); ++i)
  {
    int t = ((int)msg[i])-65 + ((int)key[i])-65;
    if (t > 25)
    {
      t = t - 26;
    }

    msg[i] = t + 65;
  }
  return msg;
}

std::string decrypt(std::string msg, std::string key)
{
  unsigned int x = 0;
  std::string t = key;
  key.erase(key.begin(), key.end());

  for (std::string::size_type i = 0; i<msg.length(); i++)
  {
    key.push_back(t[x++]);
    if (x>t.length()-1)
    {
      x = 0;
    }
  }

  for (std::string::size_type i = 0; i<msg.length(); ++i)
  {
    int t = ((msg[i])-65) - ((key[i])-65);
    if (t < 0)
    {
      t = t + 26;
    }
    msg[i] = t+65;
  }
  return msg;
}

int main()
{
  std::cout<<encrypt("THECAKEISALIE", "GLADOS");
  std::cout<<std::endl;
  std::cout<<decrypt("ZSEFOCKTSDZAK", "GLADOS");

  return 0;
}
