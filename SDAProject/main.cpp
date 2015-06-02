#include <iostream>
#include "MapDVector.h"
#include "AnagramController.h"
#include "Console.h"
#include "Repository.h"
#include "FileRepository.h"
#include "testMapDVector.h"
#include "testSSLL.h"

using namespace std;

int main() {
  test_all();
  test_ssll();
//  FileRepository *repo = new FileRepository();
//  AnagramController *ctrl = new AnagramController(repo);
//  Console *console = new Console(ctrl);
//  console->run();
  return 0;
}