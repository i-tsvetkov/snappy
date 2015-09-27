#include <iostream>
#include <vector>
#include <string>
#include <snappy.h>

using namespace std;
using namespace snappy;

int main(int argc, char *argv[])
{
  string cmd("");

  if (argc > 1)
    cmd = argv[1];

  if (argc != 2 || (cmd != "-c" && cmd != "-d"))
  {
    cerr << "usage: -c|-d" << endl;
    return 1;
  }

  vector<char> input;

  for(char c; cin.read(&c, 1); input.push_back(c));

  string output;

  if (cmd == "-c")
    Compress(input.data(), input.size(), &output);
  else if (cmd == "-d")
    if (!Uncompress(input.data(), input.size(), &output))
    {
      cerr << "decompression error!" << endl;
      return 1;
    }

  for (auto c : output)
    cout << c;
}

