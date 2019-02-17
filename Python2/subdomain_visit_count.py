class Solution(object):
    def subdomainVisits(self, cpdomains):
        count_maps = {}
        for element in cpdomains:
            counts, domain = element.split()  # O(n)
            counts = int(counts)
            while True:
                # O(1) in average case. O(n) for worst case
                if domain not in count_maps:
                    count_maps[domain] = counts  # O(1)
                else:
                    count_maps[domain] += counts  # O(1)
                dot_index = domain.find('.')  # O(n)
                if dot_index < 0:
                    break
                domain = domain[dot_index+1:]  # O(n)
        # O(len(count_maps))
        return [('%s %s' % (v, k)) for k, v in count_maps.iteritems()]


if __name__ == '__main__':
    cpdoains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com",
                "5 wiki.org"]
    sol = Solution()
    print sol.subdomainVisits(cpdoains)
