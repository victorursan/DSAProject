#include <iostream>
#include "MapDVector.h"
#include "AnagramController.h"
#include "SecondAnagramController.h"
#include "Console.h"
#include "Repository.h"
#include "FileRepository.h"
#include "testMapDVector.h"
#include "testSSLL.h"
#include "testMapHash.h"


using namespace std;

int main() {
  test_all_mapDVector();
  test_all_mapHash();
  test_ssll();
  FileRepository *repo = new FileRepository();
//  AnagramController *ctrl = new AnagramController(repo);
  SecondAnagramController *ctrl = new SecondAnagramController(repo);
  Console *console = new Console(ctrl);
  console->run();
  return 0;
}