---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'Designing nodes'
nav_order: 5
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# Project 3: {{page.title}}

## General guidelines
Designing your nodes is something that needs to make sense to you and you can
understand. That being said, you should try to write readable code, and not a
nest of if/else and variables named `a` and `b`. Failing that you should leave
comments on __why__ you are doing things. Comments like `Get child` don't really
help. I also recommend making small functions focusing on one thing. Take a look
at the next example, and think of which is more readable. Obviously we are
omitting some things here. But the more complex your code is, the more you have
to gain from this!
```c++

TIndex outIndex;
TKey key;

for(int i = 0; i < 5; i++) {
    if (data[i] == key) {
        outIndex = data[i];
    }
}


outIndex = findElement(key);
```

Ok with that out of the way, this project is probably a **good** use-case of
making the tree a friend of the node, so it can access private members. Yes, you
can do everything in the OOP way if you want. You won't be penalized either way.

<div class="alert alert-warning">
    Your nodes <b>WILL</b> have to be templated on the key and index as well!
</div>

## General Ideas
B-Trees grow from the bottom up. That means you probably want to keep track of
each node's parent on top of each node's children. Another property that might
come up a lot is the height. Recall that a leaf has a height of 0. Maybe you
want to keep track of it. Maybe you want to use it as a decreasing value in
recursion, to detect a leaf.


## Design Ideas
Next we will go over some design ideas. Please note that this is just to get you
started, and obviously doesn't cover everything. You will have to expand on
these. Also, it is VERY possible for you to come up with different designs. That
is totally fine as well. Just please leave some comments on _how_ your nodes
work and _why_.

### Idea 1: Single Node class
In this design you have a single node class and you use flags to treat it as a
leaf or internal node. For instance, you have a boolean to denote if the node is
a leaf and every node has a vector for "items". But the vector is populated for
leaves only. This potentially wastes quite a bit of memory. You can see an
example below:

```c++
template<typename TKey, typename TIndex>
class Node {
private:
    bool m_IsLeaf;
    std::vector<TKey> m_Keys;
    std::vector<Node<TKey, TIndex>*> m_Children;
    std::vector<TIndex> m_Data;
};
```

### Idea 2: Different Node classes
This is a simple extension to the above. In _my_ opinion this only introduces
more pain, over the previous idea. But remember, it is all about what makes 
sense to you, so you can implement it! You either have your m_Children vector 
populated and m_Leaves is empty, or the other way around.

```c++
template<typename TKey, typename TIndex>
class Leaf {
private:
    std::vector<TIndex> m_Data;
};

template<typename TKey, typename TIndex>
class Node {
private:
    std::vector<TKey> m_Keys;
    std::vector<Node<TKey, TIndex>*> m_Children; // You either have these
    std::vector<LeafNode<TIndex>*> m_Leaves; // OR you either have these
};
```

### Idea 3: Inheritance!
This is the most "elegant" solution, but you might not feel comfortable with it.
It is definitely the most OOP solution. LeafNode is a Node, so it gets access to
all of its protected and public members and that adds Data on top. Furthermore
we will override the behavior of `IsLeaf` so `m_Children[i]->IsLeaf()` will
return true or false as expected. This is called polymorphism from your 202
class. Please note the constructors and destructors. They **MUST** be like that.
Furthermore, `arguments for LeafNode` can include `arguments for Node`.


```c++
template<typename TKey, typename TIndex>
class Node {
protected:
    std::vector<TKey> m_Keys;
    // Children can be Node<TKey, TIndex> or LeafNode<TKey, TIndex>
    std::vector<Node<TKey, TIndex>*> m_Children;

public:
    Node(/*arguments_for_node*/);
    virtual Node();

    virtual bool IsLeaf() const { return false; }
};

template<typename TKey, typename TIndex>
class LeafNode: public Node<TKey, TIndex> {
private:
    std::vector<TIndex> m_Data;
    
public:
    LeafNode(/*arguments for LeafNode*/)
        : Node(/*arguments for Node*/)
        /*, other stuff for LeafNode here*/
    {}
    virtual LeafNode();

    // Notice how we override the behavior of Node here
    virtual bool IsLeaf() const override  { return true; } 
};
```

### Idea 4: Nodes and entries(?)
This idea can be combined with the rest pretty easily. Basically, your Node will
have a private struct that can have keys and the next/previous link to a child.
This way you can reduce the number of vectors you have to juggle around. I named
the struct `Entry` because I am that imaginative. But you might want to use
another name. Let's look at a concrete example though. We will revisit this
picture.

<img class="d-block my-0 mx-auto" src="{{ "/assets/images/tree-color-coded.png"
| absolute_url }}" alt="">

Let's say that we have the first node there at the top. An entry would have a
key of 12, previousBranch would be a pointer to the bottom left node, and next
branch would be a pointer to the bottom middle node. The next entry would have a
key of 20 and so on and so forth.

Again this is just an idea, and might warrant a lot of refinement. For instance
think of the entry when you do not have a previous or next branch.

```c++
template <typename TKey, typename TIndex>
class Node {
private:
    struct Entry {
        TKey key;
        Node<TKey, TIndex>* previousBranch;
        Node<TKey, TIndex>* nextBranch;
    };

    std::vector<Entry> m_Entries;

public:

};
```