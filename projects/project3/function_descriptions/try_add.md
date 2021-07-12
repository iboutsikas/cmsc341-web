---
layout: default
parent: "Function Descriptions"
grand_parent: "Project 3: B is NOT for binary"
title: 'BTree::try_add'
nav_order: 2
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# BTree::try_add
```c++
bool BTree::try_add(const TKey& key, const TIndex& inIndex)
```
## Description
<p>Attempts to add a new element to the tree. </p>

<p>
    You can assume that the key implements all of the standard operators (i.e.
    <code> &gt;, &lt;, &geq;, &leq;, == </code>). You can also assume that there
    is a <code>TKey == TIndex</code>
    operator.
</p>

## Parameters
* **key**: The key for this element
* **inIndex**: The input element to be added to the tree

## Return
If the element was added successfully the function should return true. If the
element already exists, the function should return false **and not modify the
tree**. In any other case the function should return false **and not modify the
tree**.