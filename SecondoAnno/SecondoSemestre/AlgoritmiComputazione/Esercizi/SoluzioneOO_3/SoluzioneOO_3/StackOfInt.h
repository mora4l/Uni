#if !defined(STACK_OF_INT)
#define STACK_OF_INT

#include <vector>

// Abstract interface of an iterator object
class StackOfIntIterator
{
public:
	virtual ~StackOfIntIterator() = default;

	virtual int current() const = 0;
	virtual void next() = 0;
	virtual bool hasNext() const = 0;
	virtual void restart() = 0;
};

// Stack of int
class StackOfInt
{
public:
	StackOfInt() = default;
	~StackOfInt() = default;

	StackOfInt(StackOfInt const &) = default;
	StackOfInt &operator=(StackOfInt const &) = default;

	// Stack methods
	int pop()
	{
		int value = heap_.back();
		heap_.pop_back();
		return value;
	}
	void push(int value)
	{
		heap_.push_back(value);
	}
	int top()
	{
		return heap_.back();
	}

	// Factory method to get an iterator
	StackOfIntIterator *getIterator()
	{
		return new InternalIterator{heap_};
	}

private:
	std::vector<int> heap_;

	// Private class for iteration: use of iterator objects through
	// the public interface of StackOfIntIterator does not break
	// incapsulation;
	class InternalIterator : public StackOfIntIterator
	{

	public:
		InternalIterator(std::vector<int> const &heap) : begin_{heap.begin()}, end_{heap.end()}, pos_{heap.begin()} {}

		int current() const override
		{
			return *pos_;
		}
		void next() override
		{
			++pos_;
		}
		bool hasNext() const override
		{
			return pos_ != end_;
		}
		void restart()
		{
			pos_ = begin_;
		}

	private:
		std::vector<int>::const_iterator begin_;
		std::vector<int>::const_iterator end_;
		std::vector<int>::const_iterator pos_;
	};
};

#endif
