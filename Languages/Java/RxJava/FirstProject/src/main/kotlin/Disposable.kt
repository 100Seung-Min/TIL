import io.reactivex.Maybe
import io.reactivex.Observable
import io.reactivex.Single
import io.reactivex.disposables.CompositeDisposable

class Disposable {
}

fun main() {
    disposable()
}

private fun disposable() {
    val compositeDisposable = CompositeDisposable()
    compositeDisposable.addAll(
        Observable.just(1).subscribe(),
        Single.just(1).subscribe(),
        Maybe.just(1).subscribe()
    )
    compositeDisposable.clear()
}