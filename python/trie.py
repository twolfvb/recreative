class TrieNode:
    def __init__(self):
        self.children = {}
        self.isCompleteWord = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add_word(self, word):
        trie = self.root
        for letter in word:
            if trie.children.get(letter):
                trie = trie.children[letter]
            else:
                trie.children[letter] = TrieNode()
                trie = trie.children[letter]
        trie.isCompleteWord = True

    def is_on_trie(self, word):
        node = self.root
        for letter in word:
            if node.children.get(letter):
                node = node.children[letter]
            else:
                return False
        if node.isCompleteWord:
            return True
        else:
            return False

    def is_word_prefix(self, prefix):
        node = self.root
        for letter in prefix:
            if node.children.get(letter):
                node = node.children[letter]
            else:
                return False
        return node

    def print_words(self, prefix, node):
        keys = node.children.keys()
        if node.isCompleteWord:
            print prefix

        for key in node.children.keys():
            Trie.print_words(self, prefix+key, node.children.get(key))


    # def return_words_with_prefix(self, prefix):
    #     prefix_node = self.is_word_prefix(prefix)
    #     words = []
    #     if prefix_node:
    #         if prefix_node.isCompleteWord:
    #     else:
    #         return 0

a = Trie()
a.add_word("meme")
a.add_word("leme")
a.add_word("memo")
a.add_word("melon")
a.add_word("mendez")

print a.is_on_trie("me")
print a.is_on_trie("meme")
print a.is_on_trie("memo")
print a.is_on_trie("mem")
print a.is_word_prefix("m") is not False
print a.is_word_prefix("me") is not False
print a.is_word_prefix("mem") is not False
a.print_words("mem", a.is_word_prefix("mem"))
