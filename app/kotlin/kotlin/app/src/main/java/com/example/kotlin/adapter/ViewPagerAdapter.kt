package com.example.kotlin.adapter

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.viewpager.widget.PagerAdapter
import com.example.kotlin.R
import kotlinx.android.synthetic.main.viewpage.view.*

class ViewPagerAdapter :PagerAdapter() {
    private var mContext: Context?=null

    fun ViewPagerAdapter(context: Context){
        mContext=context;
    }

    override fun instantiateItem(container: ViewGroup, position: Int): Any {
        val view=LayoutInflater.from(container.context).inflate(R.layout.viewpage, container, false)
        view.title.text="TEXT"+position
        container.addView(view)
        return view
    }

    override fun destroyItem(container: ViewGroup, position: Int, `object`: Any) {
        container.removeView(`object` as View?)
    }

    override fun getCount(): Int {
        return 5
    }

    override fun isViewFromObject(view: View, `object`: Any): Boolean {
        return (view==`object`)
    }
}