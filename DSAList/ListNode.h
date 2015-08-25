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