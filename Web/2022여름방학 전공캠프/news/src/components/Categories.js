import { NavLink } from 'react-router-dom';
import styled, {css} from 'styled-components';

const categories = [
  {
    name: 'all',
    Text: '전체보기'
  },
  {
    name: 'business',
    Text: '비즈니스'
  },
  {
    name: 'entertainment',
    Text: '엔터테이먼트'
  },
  {
    name: 'health',
    Text: '건강'
  },
  {
    name: 'science',
    Text: '과학'
  },
  {
    name: 'sports',
    Text: '스포츠'
  },
  {
    name: 'technology',
    Text: '기술'
  },
];

const CategoriesBlock = styled.div`
  display: flex;
  padding: 1rem;
  width: 768px;
  margin: 0 auto;
  @media screen and (max-width: 768px) {
    width: 100%;
    overflow-x: auto;
  }
`;

const Category = styled(NavLink)`
  font-size: 1.125rem;
  cursor: pointer;
  white-space: pre;
  text-decoration: none;
  color: inherit;
  padding-bottom: 0.25rem;

  &:hover {
    color: #495057;
  }

  &.active {
    font-weiht: 600;
    border-bottom: 2px solid #22b8cf;
    color: #22b8cf;
    &:hover {
      color: #3bc9db;
    }
  }

  & + & {
    margin-left: 1rem;
  }
`;

const Categories = ({onSelect, category}) => {
  return (
    <CategoriesBlock>
      {categories.map(c => (
        <Category 
          key={c.name}
          className={({istActive}) => (istActive ? 'active' : undefined)}
          to={c.name === 'all' ? '/' : `${c.name}`}
        >
          {c.Text}
        </Category>
      ))}
    </CategoriesBlock>
  )
}

export default Categories;