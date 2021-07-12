---
layout: default
parent: "Function Descriptions"
grand_parent: "Project 3: B is NOT for binary"
title: 'BTree::try_find'
nav_order: 3
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# BTree::try_find
```c++
bool BTree::try_find(const TKey& key, TIndex& outIndex) const
```
## Description
<p>
    Attempts to find the element in the tree. If the key was not found, the function
    does not modify <code>outIndex</code> <b>in any way</b>.
</p>

<p>
    You can assume the TIndex assignment operator will be enough to copy the
    TIndex you found to <code>outIndex</code>.
</p>

<p>
    You can assume that the key implements all of the standard operators (i.e.
    <code> &gt;, &lt;, &geq;, &leq;, == </code>). You can also assume that there
    is a <code>TKey == TIndex</code>
    operator.
</p>

## Parameters
* **key**: The key for this element
* **outIndex**: The output parameter

## Return
If the element was found the function should return true, and set `outIndex` to
the found element. If the
element does not exist, the function should return false. In any other case the
function should return false.