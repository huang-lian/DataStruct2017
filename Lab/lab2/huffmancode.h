#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H
class HuffmanCode{
  public:
    HuffmanCode(void);

    // 生成实例时,依据特定文件指定编码规则
    // 文件是一个普通的文本文件
    // 文件名长度至多255字符长度.
    // 文件不存在,则不依据此规则.
    HuffmanCode(const char *encode_rule);
    HuffmanCode(const HuffmanCode &huffobj);
    const HuffmanCode &operator=(const HuffmanCode &huffobj);
    ~HuffmanCode(void);

    // 将src_file进行Huffman编码,并写入文件encoded_file.
    // 编码规矩依据本文或者生成实例时指定规则文件.
    // 文件名不可为空;src_file不存在;decode_file文件存在覆盖,否则创建.
    // 文件名长度至多255字符长度.
    bool Encode(const char * src_file, const char * encoded_file);

    // 依据编码文件src_file译码并写入文件decoded_file.译码成功返回true.
    // 译码规则不可指定.依据src_file 自动译码.
    // 文件名不可为空;src_file不存在或者非本程序创建译码失败;decode_file文件存在覆盖,否则创建.
    // 文件名长度至多255字符长度.
    bool Decode(const char * src_file, const char * decoded_file);

    // 清除编码规则
    void clear(void);
    
    // 指定编码规则
    // 依据特定文件指定编码规则
    // 文件是一个普通的文本文件
    // 文件名长度至多255字符长度.
    // 文件不存在,指定失败,保存之前状态,返回false.
    bool set_rule(const char * encoded_file);

    // more
    bool Compress(const char * decoded_file);
    bool UnCompress(const char * decoded_file);
  private:

    enum { BITS_SIZE = 8, CHAR_NUM = 256};

    // 每个字符对应一个Huffman编码
    struct CodeNode{
      char ch;
      char bits[BITS_SIZE];
      CodeNode(char c):ch(c),bits[BITS_SIZE](0);
    };

    // 一个huffman 编码表
    typedef CodeNode CodeTable[CHAR_NUM];
    CodeTable encode_table_;

    struct HuffmanNode{
      size_t weight;
      char ch;
      int lchild;
      int rchild;
      int parent;
      HuffmanNode(size_t w):weight(w),lchild(-1),rchild(-1),parent(-1){
      };
      bool operator<(const HuffmanNode & hfcode) {
	return weight < hfcode.weight;
      }
    };
	
    typedef HuffmanNode HuffmanTree[2*CHAR_NUM + 1];

    HuffmanTree huffman_tree_;

    // 依据文章设置编码权重
    bool SetCharWeight(const char * encoded_file);

    // 依据字符权重设置huffman二叉树以及编码表编码
    bool CreateHuffmanTree(void);
    bool set_code_table(void);

};
#endif // HUFFMAN_CODE_H

