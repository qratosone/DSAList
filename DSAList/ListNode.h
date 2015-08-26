#define Posi(T) ListNode<T>*
typedef int Rank;
template <typename T> class ListNode {
public:
	T data;
	Posi(T) pred;
	Posi(T) succ;
	ListNode() {}
	ListNode(T e,Posi(T) p=NULL,Posi(T) s=NULL):data(e),pred(p),succ(s){}
	Posi(T) insertAsPred(T const& e) {
		Posi(T) x = new ListNode(e, pred, this);
		pred->succ = x;
		pred = x;
		return x;
	};
	Posi(T) insertAsSucc(T const& e) {
		Posi(T) x = new ListNode(e, this, succ);
		succ->pred = x;
		succ = x;
		return x;
	};
	
};
template <typename T> class List {
private:
	int _size;
	Posi(T) header;
	Posi(T) trailer;
protected:

public:
	void init() {
		header = new ListNode<T>;
		trailer = new ListNode<T>;
		header->succ = trailer;
		trailer->pred = header;
		_size = 0;
	}
	Posi(T) find(T const& e, int n, Posi(T) p)const {
		while (0 < n--) {
			if (e==(p=p->pred)->data)
			{
				return p;
			}
		}
		return NULL;
	}
	Posi(T) insertBefore(Posi(T) p, T const& e) {
		_size++;
		return p->insertAsPred(e);
	}
	Posi(T) insertAsLast(T const& e) {
		insertBefore(trailer, e);
	}
	void copyNodes(Posi(T) p, int n) {
		init();
		while (n--)
		{
			insertAsLast(p->data);
			p = p->succ;
		}
	}
	Posi(T) insertAsFirst(T const& e){
		_size++;
		header->insertAsSucc(e);
	}
	Posi(T) insertBefore(Posi(T) p,T const& e){
		_size++;
		p->insertAsPred(e);
	}
	Posi(T) insertAfter(Posi(T) p,T const& e){
		_size++;
		p->insertAsSucc(e);
	}
	List(Posi(T) p,int n){ // 从P开始复制n个节点
		copyNodes(p,n);
	}
	List(List<T> const& L){//整体复制一个列表
		copyNodes(L.first(),L._size);
	}
	List(List<T> const& L,int r,int n){  //循秩复制
		copyNodes(L[r],n);
	}
	T remove(Posi(T) p){
		T e=p->data;
		p->pred->succ=p->succ;
		p->succ->pred=p->pred;
		delete p;
		_size--;
		return e;
	}
	

};
template <typename T>
T List<T>::operator[](Rank r) const {
	Posi(T) p = first();
	while (0<r--)
	{
		p = p->succ;
	}
	return p->data;
}