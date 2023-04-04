import io.reactivex.*
import java.lang.IllegalStateException

class ObservableType {
}
fun main() {
    observable()
    single()
    completable()
    maybe()
    flowable()
}

private fun observable() {
    val observer = Observable.just(11, 12, 13)
        .map {
            if (it == 12) throw IllegalStateException()
            else it
        }

    observer.subscribe(
        { println("onNext $it") }, // onNext
        { println("onError") }, // onError
        { println("onComplete") }, // onComplete
        { println("onSubscribe") } // onSubscribe
    )
}

private fun single() {
    Single.just(1)
        .subscribe(
            { println("onSuccess $it") },
            { println("onError") }
        )
}

private fun completable() {
    Completable.complete()
        .subscribe(
            { println("onComplete") },
            { println("onError") }
        )
}

private fun maybe() {
    Maybe.empty<Unit>()
        .subscribe(
            { println("onSuccess $it") },
            { println("onComplete") },
            { println("onError") }
        )
}

private fun flowable() {
    Flowable.just(1, 2, 3, 4)
        .subscribe(
            { println("onNext $it") }, // onNext
            { println("onError") }, // onError
            { println("onComplete") }, // onComplete
            { println("onSubscribe") } // onSubscribe
        )
}