---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'B-Trees'
nav_order: 2
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# Project 3: {{page.title}}

<p>
    You should already be familiar with the theory on B-Trees. Reminder that you
    can find Professor Lupoli's playlist on 
    <a href="[http://](https://youtube.com/playlist?list=PLUg55fjW433pBtQzr5k4imW8gcnqEHowB)" 
    target="_blank" rel="noopener noreferrer">YouTube</a>, and embedded below.
</p>

<div class="iframe-container">
    <iframe width="560" height="315"
        src="https://www.youtube.com/embed/videoseries?list=PLUg55fjW433pBtQzr5k4imW8gcnqEHowB"
        title="YouTube video player" frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
        allowfullscreen></iframe>
</div>

<p>
    To avoid having to deal with real databases and hardware your trees will
    have to work in a particular way. Specifically, your trees will have to use
    keys just like the videos, but the data they are storing will be indexes
    that the "Database" will use to find the real records. Please note that an
    index can be a complex data type, instead of an integer. Do not worry, we
    will have examples and give you some classes to work with (just like we did
    in project 2)!
</p>

<p>
    In this assignment you will <b>NOT</b> have to worry about the calculation
    of optimal M and L. You will be accepting those parameters as arguments in
    your tree's constructor and using them. <b>You still have to promote and split based on those values</b>.
</p>

## The power of a name
<p>
    Before we get into the requirements, let's go over some nomenclature so
    everybody is on the same page. Let's take a look at the picture below.
</p>
<ul>
    <li>Everything red is a node, and specifically an "internal node". In the
    picture below you have 3 internal nodes. 12 is not a node. 12 and 20 together are also not a node.</li>
    <li>Everything
        colored light blue is a key. Notice how a node is <b>NOT</b> a key. A node does
        contain some keys though!</li>
    <li>Everything colored green is a branch. Notice how a node might have some
    branches, but notice how branches extend "outside" the node. That's because they symbolize
    a relationship between nodes.</li>
    <li>Everything colored orange is also a node, but this time it is a data
    node or data leaf.</li>
    <li>Everything in white color is a record, or data. Notice how 5 is
    both a key, and part of a record. These two are semantically different!</li>
    <li>Finally, everything inside the yellow line is the whole B-Tree!</li>
</ul>
<p>
We only included a single data leaf for brevity. You would normally have a lot
more. Also in your implementation, each record will be some form of index that
the database will use. You don't care how it will be used. All you care about,
is that there should be a <code>Key == Record</code> operator. The classes we
give you will provide that operator.
</p>

<p>
For your assignment the keys (12, 20, 5, 15, etc in the example) will be of type
<code>TKey</code>. The records (or data) will be of type <code>TIndex</code>. In
the example <code>TKey</code> is <code>int</code> and <code>TIndex</code> is a
<code>struct</code> that contains information about the server and path where
the data is stored. Plus some number (let's say it is the disk sector or something).
</p>

<img class="d-block my-0 mx-auto" src="{{ "/assets/images/tree-color-coded.png"
| absolute_url }}" alt="">

<div class="alert alert-info">
    In the above diagram we denote a difference between an internal node and a
    leaf node. Implementation wise, those two could be the same class, different
    classes, or different classes where Leaf inherits from Node. This is a
    design decision that you have to make!
</div>