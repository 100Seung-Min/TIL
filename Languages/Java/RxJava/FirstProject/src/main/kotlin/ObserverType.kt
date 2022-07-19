import io.reactivex.Observable
import io.reactivex.Observer
import io.reactivex.disposables.Disposable

class ObserverKind {
}

fun main() {
    observerInterface()
    observerInterface()
}

private fun observerInterface() {
    val observer = object : Observer<Int> {
        override fun onSubscribe(d: Disposable) {
            // Observable이 데이터 전달할 준비가 되었을때.
            // 작업 취소를 위한 Disposable에 대한 레퍼런스를 받음
        }

        override fun onNext(t: Int) {
            // Observable이 데이터를 전달할 때 호출
        }

        override fun onError(e: Throwable) {
            // Observable이 에러를 전달할 때 호출.
            // Error시 Complete 없이 종료된다
        }

        override fun onComplete() {
            // Observable이 완료된 경우
        }
    }
    Observable.just(1, 2, 3, 4).subscribe(observer)
}

private fun observerConsumer() {
    val disposable: Disposable = Observable.just(1, 2, 3, 4)
        .subscribe(
            { println("onNext $it") }, // onNext
            { println("onError") }, // onError
            { println("onComplete") }, // onComplete
            { println("onSubscribe") } // onSubscribe
        )
}