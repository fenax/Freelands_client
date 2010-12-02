/**
 * @file
 * @author  Guillaume Minet "Fenax" <mail@fenax.name>
 *
 * @section LICENSE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * An implementation of a queue.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <queue>
#include <deque>
#include <boost/noncopyable.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/mutex.hpp>
namespace Tools
{

template<typename T>
class Queue : public std::queue<T,std::deque<T> >, boost::noncopyable
{
private:
	boost::mutex mutex_;
public:

//	empty	Test whether container is empty (public member function)
	bool
	empty(){
		boost::unique_lock<boost::mutex> lock(mutex_);
		return std::queue<T,std::deque<T> >::empty();
	}
	size_t
	size(){
		boost::unique_lock<boost::mutex> lock(mutex_);
		return std::queue<T,std::deque<T> >::size();
	}
	//	front	Access next element (public member function)
	T&
	front(){
		boost::unique_lock<boost::mutex> lock(mutex_);
		return std::queue<T,std::deque<T> >::front();
	}
	//	back	Access last element (public member function)
	T&
	back(){
		boost::unique_lock<boost::mutex> lock(mutex_);
		return std::queue<T,std::deque<T> >::back();
	}
	//	push	Insert element (public member function)
	void
	push ( const T& x ){
		boost::unique_lock<boost::mutex> lock(mutex_);
		std::queue<T,std::deque<T> >::push(x);
		return;
	}
	//	pop	Delete next element (public member function)
	void
	pop(){
		boost::unique_lock<boost::mutex> lock(mutex_);
		std::queue<T,std::deque<T> >::pop();
	}
};

}

#endif /* QUEUE_H_ */
