---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'Assignment'
nav_order: 3
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# Project 3: {{page.title}}

<p>
Your assignment is to implement a B-Tree, that will be used by a "database" to
quickly index data. We will be providing some starter code, but that is
mainly the template setup. You are free to design your own implementations as
you see fit, as long as you do not change the provided interface. <b>That means
you cannot change the function signatures we give you (including the
constructors).</b> The required functions can call other functions that you
build though. And you are in control of those other functions.
</p>

<p>
    Your B-Tree <b>MUST</b> fulfill the interface below. All functions return a
    boolean showing their success or failure. The return of the value happens
    through an "out parameter". We discuss those in their own section.
</p>
```c++
template <typename TKey, typename TIndex>
class BTree {
    int m_Degree;
    int m_LeafSize;
public:
    BTree(int m, int l)
        : m_Degree(m)
        , m_LeafSize(l)
    {}

    bool try_add(const TKey& key, const TIndex& inIndex)
    {
        return false;
    }

    bool try_find(const TKey& key, TIndex& outIndex) const
    {
        return true;
    }

    bool try_update(const TKey& key, const TIndex& inIndex) const
    {
        return false;
    }

    bool try_delete(const TKey& key) { return false; }
};
```

<div class="alert alert-info">
    Please note that we do not show a Node class here. You will need such a
    class, but we discuss it in a different section.
</div>

<p>
While designing your tree, you can use recursion and iteration as you see fit.
Trees are inherently recursive structures, so you should often find yourself
using that. But some things are easier to do iteratively!
</p>
