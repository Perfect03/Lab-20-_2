#ifndef OBSERVABLE_H
#define OBSERVABLE_H
 
#include <set>
#include <vector>
 
template<class FileObserver>
class Observable {
public:
    virtual ~Observable() {
    }
 
    void registerObserver(FileObserver* observer) {
        if(m_count != 0) {
            m_requests.push_back(ObserverRequest { &Observable<FileObserver>::registerObserver, observer } );
        } else if(observer) {
            m_observers.insert(observer);
        }
    }
 
    void unregisterObserver(FileObserver* observer) {
        if( m_count != 0 ) {
            m_requests.push_back( ObserverRequest { &Observable< FileObserver >::unregisterObserver, observer } );
        } else if(observer) {
            m_observers.erase(observer);
        }
    }
 
protected:
    Observable() : m_count(0) {
    }
 
    template< typename F, typename... Args >
    void notifyObservers(F f, Args... args) {
        ++m_count;
        for(FileObserver* o : m_observers) {
            (o->*f)(args...);
        };
        --m_count;
        if(m_count == 0) {
            for(const ObserverRequest& r : m_requests) {
                (this->*r.operation)(r.observer);
            };
            m_requests.clear();
        }
    }
 
private:
    struct ObserverRequest {
        void (Observable<FileObserver>::*operation)(FileObserver*);
        FileObserver* observer;
    };
 
    std::set<FileObserver*> m_observers;
    int m_count;
    std::vector<ObserverRequest> m_requests;
};
 
#endif // OBSERVABLE_H
