SELECT lb.book_id,
       lb.title,
       lb.author,
       lb.genre,
       lb.publication_year,
       lb.total_copies AS current_borrowers
FROM library_books lb
INNER JOIN borrowing_records br
    ON br.book_id = lb.book_id
WHERE br.return_date IS NULL
GROUP BY lb.book_id,
         lb.title,
         lb.author,
         lb.genre,
         lb.publication_year,
         lb.total_copies
HAVING COUNT(*) = lb.total_copies
ORDER BY current_borrowers DESC, lb.title;
