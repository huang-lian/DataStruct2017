#include<iostream>
#include"../share_stack/share_stack.h"
//#define TEST
class Train{
  public:
    Train(const int *train_in,const int *train_out, int n); 
    ~Train(void);

    bool Result(void) const;
    void ShowTrain(void) const;

  private:
    bool flag_;
    int n_;
    int *train_in_;
    int *train_out_;
};

Train::Train(const int *train_in,const int *train_out, int n) {
  flag_ = true;
  n_ = n;
  train_in_ = new int[n_];
  train_out_ = new int[n_];
  for(int i = 0; i < n_; i++) {
    train_in_[i] = train_in[i];
    train_out_[i] = train_out[i];
  }

  // set flag
  ShareStack<int> st;
  int j = 0;
  for(int i = 0; i < n_;) {
#ifdef TEST
    st.ShowStack();
#endif // TEST
    if (st.IsEmpty()) {
#ifdef TEST
      std::cout << "Push: " << train_in_[j] << std::endl;
#endif // TEST
      st.Push(train_in_[j++]);
    } else if (st.Top() == train_out_[i]) {
#ifdef TEST
      std::cout << "Pop: " << st.Top() << std::endl;
#endif // TEST
      st.Pop();
      i++;
    } else if (j < n_){
#ifdef TEST
      std::cout << "Push: " << train_in_[j] << std::endl;
#endif // TEST
      st.Push(train_in_[j++]);
    } else {
      flag_ = false; 
      break;
    }
  }
}
Train::~Train(void) {
  delete [] train_in_;
  delete [] train_out_;
}
bool Train::Result(void) const {
  return flag_;
}
void Train::ShowTrain(void) const {
  std::cout << "train into as:\n";
  std::cout << "pre---> end(top)\n";
  for(int i = 0; i < n_; i++) {
    std::cout << train_in_[i] << "\t";
  }
  std::cout << std::endl;

  std::cout << "train out as:\n";
  std::cout << "pre---> end(top)\n";
  for(int i = 0; i < n_; i++) {
    std::cout << train_out_[i] << "\t";
  }
  std::cout << std::endl;
}

int main(void) {
  using namespace std;
  int n = 1;

  while( 0 != n) {
    cout << "===New Loop===============\n";
    cout << "Input n:\n";
    cin >> n;
    if (0 >= n)
      break;

    int *in = new int[n];
    int *out = new int[n];

    cout << "Input train in:\n";
    for(int i = 0; i < n; i++) {
      cin >> in[i];
    }
    cout << "Input train out:\n";
    for(int i = 0; i < n; i++) {
      cin >> out[i];
    }

    Train t(in, out, n);
    t.ShowTrain();

    if (t.Result()) {
      cout << "Can.\n";
    } else {
      cout << "Can't.\n";
    }
  }
  return 0;
}
