package com.example.studymvvm.ui.adapter

import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.text.TextUtils
import android.view.LayoutInflater
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.example.studymvvm.R
import com.example.studymvvm.ui.model.RepoItem

class RepositoryAdapter: RecyclerView.Adapter<RepositoryAdapter.ViewHolder>() {

    class ViewHolder(parent: ViewGroup): RecyclerView.ViewHolder(
        LayoutInflater.from(parent.context)
            .inflate(R.layout.item_repository, parent, false)
    )

    private var items: MutableList<RepoItem> = mutableListOf()

    private val placeholder = ColorDrawable(Color.GRAY)

    var onItemClick: ((repoItem: RepoItem) -> Unit)? = null

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int) =
        ViewHolder(parent).apply {
            itemView.setOnClickListener {
                val item = items[adapterPosition]
                onItemClick?.invoke(item)
            }
        }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        items[position].let { repo ->
            with(holder.itemView){
                Glide.with(context)
                    .load(repo.owner.ownerUrl)
                    .placeholder(placeholder)
                    .into(findViewById(R.id.ivProfile))
                findViewById<TextView>(R.id.tvTitle).text = repo.title
                findViewById<TextView>(R.id.tvLanguage).text = if(TextUtils.isEmpty(repo.language))
                    "No language specified"
                else
                    repo.language
            }
        }
    }

    override fun getItemCount() = items.size

    fun setItems(items: List<RepoItem>){
        this.items.clear()
        this.items.addAll(items)
        notifyDataSetChanged()
    }

    fun clearItems(){
        this.items.clear()
        notifyDataSetChanged()
    }
}