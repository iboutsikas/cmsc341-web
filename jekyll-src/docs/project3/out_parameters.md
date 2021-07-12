---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'Out parameters'
nav_order: 6
---

{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# Project 3: {{page.title}}

When you take a parameter by reference, you can treat it like a local, stack
allocated variable, and the caller sees the changes you make. It is in essence a
pointer, it just makes the syntax a bit simpler and you don't have to `->` 
everything.

Let's see how we use out parameter to our advantage next. Let's say we are
implementing <code>BTree::try_find</code>. You will notice that outIndex is a
TIndex reference. It is **NOT** `const`. That means we can modify it in our
function! Notice how `some_other_function` also takes a `TIndex&`. If you needed
`some_other_function` to be recursive you can add additional arguments, and when
you find what you are looking for, you just assign to the reference and return
whatever you need to return. The return value could be a boolean, it could be
the index where you found the thing, it could be many things. It depends on your
design.

```c++
some_return_type some_other_function(TIndex& outIndex) {
    // Do work to find the index (ie this function could be recursive);
    if (found)
        outIndex = ...;
    
    return something;
}

bool try_find(const TKey& key, TIndex& outIndex) 
{
    // Example 1
    outIndex = some_function(some_arguments);

    // Example 2
    some_return_value = some_other_function(outIndex);
}
```