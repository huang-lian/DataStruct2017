#include<fstream>
#include"huffmancode.h"
#include"arr_min_heap.h"
HuffmanCode::HuffmanCode(void)
{
  // #pass
}

HuffmanCode::HuffmanCode(const char *encode_rule)
{
  // #pass
}

HuffmanCode:: HuffmanCode(const HuffmanCode &huffobj)
{
  // #pass
}

const HuffmanCode::HuffmanCode &operator=(const HuffmanCode &huffobj)
{
  // #pass
}

HuffmanCode::~HuffmanCode(void)
{
  // #pass
}


bool HuffmanCode::Encode(const char * src_file, const char * encoded_file)
{
  // #pass
}


bool HuffmanCode::Decode(const char * src_file, const char * decoded_file)
{
  // #pass
}


void HuffmanCode::clear(void)
{
  // #pass
}

bool HuffmanCode::SetCharWeight(const char * encoded_file)
{
  fstream fin;
  fin.open(encoded_file,std::ios::in);
  char ch;
  if (fin.is_open()) {
    fin.get(ch);
    while(!fin.eof()) {
      // 统计权重
      huffman_tree_[int(ch)].weight++;
      fin.get(ch);
    }
  }
  return false;
  // #pass
}

// 依据设置好了huffman森林.准备生成huffman
// 使用了堆来求解权重最小和次小的树
bool HuffmanCode::CreateHuffmanTree(void)
{
  // 建立了一个
  struct Item{
    int pos;
    int weight;
    Item(int n,int w) : pos(w),weight(w) {
    };
    bool operator<(const Item &it)  {
      return weight< it.weight
    };
  };

  ArrMinHeap<Item> mhinhp(256);
  for(int i = 0; i < CHAR_NUM; i ++)
    minhp.Insert(Item(i,huffman_tree_[i].weight));

  //
  int lhspos,rhpos;
  for(int i = CHAR_NUM; i < 2*CHAR_NUM + 1; i++)
  {
    lhspos = mhinhp.Delete().pos;
    rhspos = mhinhp.Delete().pos;  // 取出最小树

    huffman_tree_[rhspos].parent = huffman_tree_[lhspos].parent = i;
    huffman_tree_[i].rchild = rhspos;
    huffman_tree_[i].lchild = lchild;
    huffman_tree_[i].weight = huffman_tree_[lhspos].weight + huffman_tree_[rhspos].weight;

    minhp.Insert(Item(i,huffman_tree_[i].weight));  // 
  }
}

// 依据建立的huffman树建立encode表
bool HuffmanCode::set_code_table(void)
{
  char tmpbits[BITS_SIZE]={0};
  int bits_start = BITS_SIZE -1;
  for(int i = 0; i < CHAR_NUM; i++) {
    encode_table_[i].ch = huffman_tree_[i].ch;
    bits_start = BITS_SIZE -1;
    int pr = i;
    for(int p = huffman_tree_[i].parent; -1 != p; p = huffman_tree_[p].parent) {
      tmpbits[--start] = (huffman_tree_[p].lchild == pr)?'0':'1';
      pr = p;
    }
  }
  strpy(encode_table_[i].bits,&tmpbits[bits_start]);
}
// more
bool HuffmanCode::Compress(const char * decoded_file)
{
  // #passvoi
}

bool HuffmanCode::UnCompress(const char * decoded_file)
{
  // #pass
}




