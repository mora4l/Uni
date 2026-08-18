#if !defined(STACK_H)
#define STACK_H

#include <vector>

// Abstract interface of an iterator object
template <class T> class StackIterator {
public:
	virtual T current() const = 0;
	virtual void next() = 0;
	virtual bool hasNext() const = 0;
	virtual void restart() = 0;
};

// Stack of int
template <class T> class Stack {
public:
	Stack() = default;
	~Stack() = default;
	Stack(StackOfInt<T> const&) = default;
	Stack& operator=(StackOfInt<T> const&) = default;

	// Stack methods
	T pop() {
		T value = heap_.back();
		heap_.pop_back();
		return value;
	}
	void push(T const& value) {
		heap_.push_back(value);
	}
	T top() {
		return heap_.back();
	}

	// Factory method to get an iterator
	StackIterator<T>* getIterator() {
		return new InternalIterator<T>{ heap_ };
	}

private:
	std::vector<T> heap_;

	// Private class for iteration: use of iterator objects through
	// the public interface of StackOfIntIterator does not break
	// incapsulation; 
	template <class T> class InternalIterator : public StackIterator<T> {

	public:
		InternalIterator(std::vector<T> const& heap) :
			begin_{ heap.begin() }, end_{ heap.end() }, pos_{ heap.begin() } {}

		T current() const override {
			return *pos_;
		}
		void next() override {
			++pos_;
		}
		bool hasNext() const override {
			return pos_ != end_;
		}
		void restart() {
			pos_ = begin_;
		}
	private:
		std::vector<T>::const_iterator begin_;
		std::vector<T>::const_iterator end_;
		std::vector<T>::const_iterator pos_;
	};
};

#endif