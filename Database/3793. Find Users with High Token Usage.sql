SELECT user_id ,count(PROMPT) AS prompt_count ,
round(SUM(TOKENS)/count(PROMPT),2) as avg_tokens
FROM PROMPTS 
GROUP BY USER_ID having count(prompt)>2 and max(tokens)>avg(tokens)
order by round(SUM(TOKENS)/count(PROMPT),2) desc,user_id
