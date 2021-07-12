---
layout: default
parent: "Function Descriptions"
grand_parent: "Project 3: B is NOT for binary"
title: 'BTree::try_delete'
nav_order: 5
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# BTree::try_delete
```c++
bool BTree::try_delete(const TKey& key)
```
## Description
<p>
    Attempts to remove the element with the given key from the tree. If the key
    was not found, the function does not modify the tree **in any way**. If the
    element is found, you must update your structure to remove it. This heavily
    depends on how you've implemented things.
</p>

<p>
    You can assume that there is nothing special you need to do with the memory
    allocated for TIndex. You only care about the memory you have allocated in
    your code.
</p>

<p>
    You can assume that the key implements all of the standard operators (i.e.
    <code> &gt;, &lt;, &geq;, &leq;, == </code>). You can also assume that there
    is a <code>TKey == TIndex</code> operator.
</p>

## Parameters
* **key**: The key for this element
* **inIndex**: The new values for the element

## Return
If the element was found the function should return true. If the
element does not exist, the function should return false. In any other case the
function should return false.