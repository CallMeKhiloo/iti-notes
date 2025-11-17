#include "terminal_utils.h"
using namespace std;

int main()
{
  gotoxy(10, 5);
  setColor(COLOR_GREEN);
  cout << "Hello from C++!" << endl;
  resetColor();
  std::this_thread::sleep_for(std::chrono::seconds(3));
  clearScreen();
  cout << "Shutting down....." << endl;
  return 0;
}